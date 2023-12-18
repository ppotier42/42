#include "Channel.hpp"
#include "Replies.hpp"
#include "Server.hpp"
#include "Replies.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

Channel::Channel(std::string const &name, Client &creator)
{
	this->name = name;
	invite_only = false;
	topic_operator = false;
	password = "";
	user_limit = 10;
	topic = "";
	operators.push_back(creator);
	users.push_back(creator);
	creator.appendSend(JOIN(creator.getNickname(), name));
	greet(creator);
}

std::string Channel::getName(void) const
{
	return (name);
}

std::string Channel::getTopic(void) const
{
	return (topic);
}

bool		Channel::getTopicOperator(void) const
{
	return (topic_operator);
}

void		Channel::setTopic(std::string top)
{
	topic = top;
}

void Channel::join(Client &client, std::string pass)
{
	if (std::find(users.begin(), users.end(), client) != users.end())
		throw std::invalid_argument("");
	if (pass != this->password)
		throw std::invalid_argument(ERR_BADCHANNELKEY(client.getNickname(), name));
	if (invite_only && std::find(invited.begin(), invited.end(), client) == invited.end())
		throw std::invalid_argument(ERR_INVITEONLYCHAN(client.getNickname(), name));
	if (user_limit > 0 && users.size() >= (unsigned int) user_limit)
		throw std::invalid_argument(ERR_CHANNELISFULL(client.getNickname(), name));
	if (std::find(banned.begin(), banned.end(), client) != banned.end())
		throw std::invalid_argument(ERR_BANNEDFROMCHAN(client.getNickname(), name));
	users.push_back(client);
}

std::vector<std::string> Channel::getUsersNicks(void) const
{
	std::vector<std::string>	resp;

	for (unsigned int i = 0; i < users.size(); i++)
		resp.push_back(users[i].getNickname());
	return (resp);
}

void	Channel::greet(Client &client)
{
	if (!topic.empty())
		client.appendSend(RPL_TOPIC(client.getNickname(), name, topic));
	else
		client.appendSend(RPL_NOTOPIC(client.getNickname(), name));
	for (unsigned int i = 0; i < users.size(); i++)
	{
		std::string prefix;
		if (std::find(operators.begin(), operators.end(), users[i]) != operators.end())
			prefix = "@";
		else
			prefix = "";
		client.appendSend(RPL_NAMREPLY(client.getNickname(), name, prefix + users[i].getNickname()));
	}
	client.appendSend(RPL_ENDOFNAMES(client.getNickname(), name));
}

bool	Channel::isInChannel(Client const &client) const
{
	return (std::find(users.begin(), users.end(), client) != users.end());
}

bool	Channel::isOperator(Client const &client) const
{
	return (std::find(operators.begin(), operators.end(), client) != operators.end());
}

void	Channel::removeFromChannel(Client const &client)
{
	std::vector<Client>::iterator match;

	match = std::find(users.begin(), users.end(), client);
	if (match != users.end())
		users.erase(match);
	match = std::find(operators.begin(), operators.end(), client);
	if (match != operators.end())
		operators.erase(match);
	match = std::find(invited.begin(), invited.end(), client);
	if (match != invited.end())
		invited.erase(match);
	match = std::find(banned.begin(), banned.end(), client);
	if (match != banned.end())
		banned.erase(match);
}

bool	Channel::getInviteOnly(void) const
{
	return (invite_only);
}

void	Channel::invite(Client &client)
{
	invited.push_back(client);
}

std::string	Channel::modeString(void) const
{
	std::string mode;
	std::string	end;

	if (invite_only)
		mode += "i";
	if (topic_operator)
		mode += "t";
	if (!password.empty())
	{
		mode += "k";
		end += " " + password;
	}
	if (user_limit != -1)
	{
        std::stringstream ss;  
        std::string tmp;
        ss << user_limit;  
        ss >> tmp;
		mode += "l";
		end += " " + tmp;
	}
	if (!mode.empty())
		mode.insert(0, "+");
	mode += end;
	return (mode);
}

void Channel::addMode(char mode, std::string args)
{
	if (mode == 'k')
		password = args;
	else if (mode == 'l')
	{
		int new_limit = atoi(args.c_str());
		if (new_limit > 0)
			user_limit = new_limit;
	}
	else if (mode == 'i')
		invite_only = true;
	else if (mode == 't')
		topic_operator = true;
}

void Channel::delMode(char mode)
{
	if (mode == 'k')
		password = "";
	else if (mode == 'l')
		user_limit = -1;
	else if (mode == 'i')
		invite_only = false;
	else if (mode == 't')
		topic_operator = false;
}

void	Channel::delOperator(std::string arg)
{
	for (unsigned int i = 0; i < operators.size(); i++)
	{
		if (operators[i].getNickname() == arg)
		{
			operators.erase(operators.begin() + i);
			break ;
		}
	}
}

void	Channel::addOperator(std::string arg)
{
	bool add = true;
	for (unsigned int i = 0; i < operators.size(); i++)
	{
		if (operators[i].getNickname() == arg)
			add = false;
	}
	if (add)
	{
		for (unsigned int i = 0; i < users.size(); i++)
		{
			if (users[i].getNickname() == arg)
			{
				operators.push_back(users[i]);
				break ;
			}
		}
	}
}

void	Channel::changeMode(std::vector<std::string> args, Client &client)
{
	std::string mode = args[1];
	std::vector<std::string> mode_args(args.begin() + 2, args.end());

	if (mode[0] != '+' && mode[0] != '-')
		return ;
	bool			add = false;
	unsigned int	args_pos = 0;
	for (unsigned int i = 0; i <  mode.length(); i++)
	{
		if (mode[i] == '+')
			add = true;
		else if (mode[i] == '-')
			add = false;
		else if (mode[i] == 'o')
		{
			if (args_pos == mode_args.size())
				client.appendSend(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
			else if (!add)
				delOperator(mode_args[args_pos++]);
			else
				addOperator(mode_args[args_pos++]);
		}
		else if (add)
		{
			if (args_pos == mode_args.size() && (mode[i] == 'k' || mode[i] == 'l'))
				client.appendSend(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
			else if (args_pos == mode_args.size()) 
				addMode(mode[i], "");
			else
				addMode(mode[i], mode_args[args_pos++]);
		}
		else
			delMode(mode[i]);
	}
}

void	Channel::changeNick(std::string old_nick, std::string new_nick)
{
	for (unsigned int i = 0; i < users.size(); i++) {
		if (users[i].getNickname() == old_nick)
			users[i].setNickname(new_nick);
	}
	for (unsigned int i = 0; i < operators.size(); i++) {
		if (operators[i].getNickname() == old_nick)
			operators[i].setNickname(new_nick);
	}
	for (unsigned int i = 0; i < invited.size(); i++) {
		if (invited[i].getNickname() == old_nick)
			invited[i].setNickname(new_nick);
	}
	for (unsigned int i = 0; i < banned.size(); i++) {
		if (banned[i].getNickname() == old_nick)
			banned[i].setNickname(new_nick);
	}
}
