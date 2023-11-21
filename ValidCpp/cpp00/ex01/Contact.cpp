/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:00:42 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 16:45:18 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::print_contact(int index) const
{
	if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty())
	{
		std::cout << "There is nothing at this index -> " << index << std::endl;
		return ;
	}
	std::cout << "Contact : " << index << std::endl;
	std::cout << "First Name : " << this->_firstname << std::endl;
	std::cout << "Last Name : " << this->_lastname << std::endl;
	std::cout << "Nickmane : " << this->_nickname << std::endl;
	
}

std::string Contact::_printlen(std::string str) const
{
	if(str.length() > 10)
		return (str.substr(0, 9) + ".");
	return(str);
}

void	Contact::_printsearch(int index) const
{
	if (this->_firstname.empty() || this->_lastname.empty() || this->_nickname.empty())
		return ;
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << this->_printlen(this->_firstname);
	std::cout << "|" << std::setw(10) << this->_printlen(this->_lastname);
	std::cout << "|" << std::setw(10) << this->_printlen(this->_nickname);
	std::cout << "|" << std::endl;
	std::cout << std::endl;
}

void	Contact::set_index(int i)
{
	this->index = i;
}

std::string	Contact::_getInput(std::string str) const {
	std::string input = "";
	int flag = 0;
	do {
		std::cout << str;
		std::getline(std::cin, input);
		if(std::cin.good() && !input.empty())
			flag = 1;
		else
		{
			std::cin.clear();
			std::cout << "Input Error" << std::endl;
		}
	} while(!flag);
	return(input);
}

void	Contact::add_contact()
{
	this->_firstname = this->_getInput("First name : ");
	this->_lastname = this->_getInput("Last name : ");
	this->_nickname = this->_getInput("Nickname : ");
	this->_number = this->_getInput("Phone number : ");
	this->_secret = this->_getInput("Darkest secret : ");
}