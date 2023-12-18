/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graux <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:56:28 by graux             #+#    #+#             */
/*   Updated: 2023/12/15 16:08:10 by graux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"
#include "Command.hpp"
#include "Replies.hpp"
#include <iostream>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <string>
#include <cstdlib>
#include <algorithm>

Server::CommMap Server::commands_map = Server::init_commands_map();

Server::Server(void)
{
}

Server::~Server(void)
{
	std::cerr << "Exiting server" << std::endl;
	logfile.close();
}

Server::Server(Server const &s)
{
	*this = s;
}

Server &Server::operator=(Server const &s)
{
	if (this == &s)
		return (*this);
	password = s.password;
	port = s.port;
	return (*this);
}

void	Server::logmsg(std::string msg)
{
	if (msg.find("\r\n") != std::string::npos)
		msg.erase(msg.size() - 2, 2);
	logfile << msg << std::endl;
	std::cout << msg << std::endl;
}

Server::Server(std::string port_str, std::string pass) : password(pass), port(port_str)
{
	logfile.open("serv.log");
	if (!logfile.is_open())
		std::cerr << "Could not open log file" << std::endl;
	try {
		iport = std::atoi(port_str.c_str());
		if (iport < 1 || iport > 65535)
			throw std::invalid_argument("Invalid port number");
	}
	catch (std::exception &e) {
		std::cerr << "Invalid port number" << std::endl;
		std::exit(EXIT_FAILURE);
	}
	char buffer[50];
	time_t	rawtime;
	time(&rawtime);
	struct tm *timeinfo = localtime(&rawtime);
	strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
	start_time = std::string(buffer);
	nicknames.push_back("botty");
	botty = Botty();
}

void	Server::lnch(void)
{
	std::cout << "Launching server..." << std::endl;
	struct addrinfo hints = {};
	struct addrinfo *p;
	struct addrinfo	*servinfo;
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	int status;
	if ((status = getaddrinfo(NULL, port.c_str(), &hints, &servinfo)) != 0) {
		std::cerr << "Error: getaddrinfo: " << gai_strerror(status);
		std::exit(1);
	}
	for (p = servinfo; p != NULL; p = p->ai_next) {
		int	sockfd;
		if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
			std::cerr << "Error: Socket" << std::endl;
			continue ;
		}
		if (fcntl(sockfd, F_SETFL, O_NONBLOCK) == -1) {
			std::cerr << "Error: fcntl" << std::endl;
			std::exit(1) ;
		}
		int okay = 1;
		if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &okay, sizeof(int)) == -1) {
			std::cerr << "Error: setsockopt" << std::endl;
			std::exit(1);
		}
		if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
			close(sockfd);
			std::cerr << "Error: bind" << std::endl;
			continue;
		}
		std::cout << "INFO: found a valid node, sockfd: " << sockfd << std::endl;
		interfaces.push_back(sockfd);
	}
	freeaddrinfo(servinfo);
	if (interfaces.empty()) {
		std::cerr << "Error: Could not find a binding" << std::endl;
		std::exit(1);
	}
	for (unsigned int i = 0; i < interfaces.size(); i++)
	{
		if (listen(interfaces[i], BACKLOG) == -1) {
			std::cerr << "Error: could not start listening" << std::endl;
			std::exit(1);
		}
	}
	std::cout << "Server launched" << std::endl;
}

void	Server::run(void)
{
	std::cout << "Server running..." << std::endl;

	std::vector<pollfd> pollfds;
	for (unsigned int i = 0; i < interfaces.size(); i++)
	{
		pollfd	listener = {};
		listener.fd = interfaces[i];
		listener.events = POLLIN;
		pollfds.push_back(listener);
	}

	while (!server_off)
	{
		int poll_count = poll((pollfd *)&pollfds[0], (unsigned int) pollfds.size(), -1);
		if (poll_count == -1) {
			if (errno == EINTR)
				break;
			throw std::exception();
		}
		for (unsigned int i = 0; i < pollfds.size(); i++)
		{
			pollfd	curr_poll = pollfds[i];
			if (curr_poll.revents & POLLIN) {
				if (std::find(interfaces.begin(), interfaces.end(), curr_poll.fd) != interfaces.end())
					this->newConnection(pollfds, curr_poll.fd);
				else
					this->recvClient(pollfds, curr_poll);
			}
			else if (curr_poll.revents & POLLOUT) {
				if (std::find(interfaces.begin(), interfaces.end(), curr_poll.fd) == interfaces.end())
					this->sendClient(pollfds, curr_poll);
			}
		}
	}
	std::cout << "Server stopped" << std::endl;
}

void	Server::newConnection(std::vector<pollfd> &pollfds, int curr_fd)
{
	struct sockaddr_storage	remoteaddr;
	socklen_t				addrlen = sizeof(remoteaddr);
	int						confd = accept(curr_fd, (struct sockaddr *)&remoteaddr, &addrlen);
	if (confd != -1)
	{
		pollfd	new_node;
		new_node.fd = confd;
		new_node.events = POLLIN | POLLOUT;
		pollfds.push_back(new_node);
		std::cout << "Run: new connection on fd: " << confd << std::endl;
		clients.insert(std::pair<int, Client>(confd, Client(confd)));
	}
	else
	{
		std::cerr << "Error: Could not accept new connection" << std::endl;
		exit(1);
	}
}

void	Server::parseMessage(Client &client)
{
	std::string	message = client.getReadBuff();
	while (message.find("\r\n") != std::string::npos && message.size() != 2)
	{
		logmsg(BLUE "<- " + client.getNickname() + ": " + client.nextRead());
		try {
			Command command(client.nextRead());
			std::string comm = command.getCommand();
			if (!client.getRegistered() && !(comm == "PASS" || comm == "NICK" || comm == "USER" || comm == "CAP"))
			{
				client.appendSend(ERR_NOTREGISTERED(client.getNickname()));
				client.clearNextRead();
				message = client.getReadBuff();
				continue ;
			}
			Exec_func	func = commands_map[command.getCommand()];
			(this->*func)(client, command);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
		client.clearNextRead();
		message = client.getReadBuff();
	}
}

void	Server::recvClient(std::vector<pollfd> &pollfds, pollfd &pfd)
{
	char	buff[BUFF_SIZE] = "";
	int	received = recv(pfd.fd, buff, BUFF_SIZE, 0);
	if (received > 0)
	{
		clients.at(pfd.fd).appendRead(buff);
		parseMessage(clients.at(pfd.fd));
	}
	else
	{
		std::cerr  << "Client disconnected from fd: " << pfd.fd << std::endl;
		close(pfd.fd);
		std::vector<std::string>::iterator match = std::find(nicknames.begin(), nicknames.end(), clients.at(pfd.fd).getNickname());
		if (match != nicknames.end())
			nicknames.erase(match);
		clients.erase(clients.find(pfd.fd));
		for (unsigned int i = 0; i < pollfds.size(); i++)
		{
			if (pfd.fd == pollfds[i].fd)
			{
				pollfds.erase(pollfds.begin() + i);
				break ;
			}
		}
	}
}

void	Server::sendClient(std::vector<pollfd> &pollfds, pollfd &pfd)
{
	(void) pollfds;
	Client		&client = clients.at(pfd.fd);
	std::string	message;
	int			sent;

	message = client.getSendBuff();
	if (message.empty())
		return ;
	logmsg(GREEN "-> " + client.getNickname() + ": " + message);
	sent = send(pfd.fd, message.c_str(), message.size(), 0);
	if (message.find(":localhost ERROR") != std::string::npos)
	{
		nicknames.erase(std::find(nicknames.begin(), nicknames.end(), client.getNickname()));
		clients.erase(clients.find(pfd.fd));
		close(pfd.fd);
		for (unsigned int i = 0; i < pollfds.size(); i++)
		{
			if (pfd.fd == pollfds[i].fd)
			{
				pollfds.erase(pollfds.begin() + i);
				break ;
			}
		}
	}
	client.clearSentSendBuff(sent);
}

bool    Server::channelExists(std::string name)
{
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == name)
			return (true);
	}
	return (false);
}

Client  &Server::clientFromNick(std::string nick)
{
	std::map<int, Client>::iterator it;
	for (it = clients.begin(); it != clients.end(); it++)
	{
		if (it->second.getNickname() == nick)
			return (it->second);
	}
	throw std::invalid_argument("Client not found");
	return (clients.at(0));
}

void	Server::broadcast(std::string msg, std::vector<std::string> const &targets)
{
	for (unsigned int i = 0; i < targets.size(); i++)
	{
		if (std::find(nicknames.begin(), nicknames.end(), targets[i]) != nicknames.end())
		{
			Client	&target = clientFromNick(targets[i]);
			target.appendSend(msg);
		}
	}
}

Channel    &Server::channelFromName(std::string name)
{
	for (unsigned int i = 0; i < channels.size(); i++)
	{
		if (channels[i].getName() == name)
			return (channels[i]);
	}
	throw std::invalid_argument("Channel not found");
	return (channels[-1]);
}

std::string	Server::getPort(void) const
{
	return (port);
}

std::ostream &operator<<(std::ostream &o, const Server &s)
{
	o << "---------Server Stats---------\n";
	o << "port: " << s.getPort() << std::endl;
	return (o);
}
