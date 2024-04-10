/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:31:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 16:50:56 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "Contact.hpp"

void	Phonebook::welcome()
{
	std::cout << std::endl;
	std::cout << "---------Usage--------" << std::endl;
	std::cout << "ADD -> Add new contact" << std::endl;
	std::cout << "SEARCH -> Search for contact" << std::endl;
	std::cout << "EXIT -> Close the Phonebook" << std::endl;
}

int	Phonebook::_readInput() const
{
	int input = -1;
	int flag = 0;
	do {
		std::cout << "Please enter contact index : ";
		std::cin >> input;
		if(std::cin.good() && (input >= 0 && input <= 8))
			flag = 1;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index, please retry" << std::flush;
		}
	} while(!flag);
	return(input);
}

void	Phonebook::search() const
{
	int	i = this->_readInput();
	this->_contact[i].print_contact(i);
}

void	Phonebook::print_contact() const
{
	for(int i = 0; i < 8; i++)
		this->_contact[i]._printsearch(i);
}

void	Phonebook::add()
{
	static int i;
	this->_contact[i % 8].add_contact();
	this->_contact[i % 8].set_index(i % 8);
	i++;
}

int main(void)
{
	Phonebook	phonebook;

	std::string prompt = "";
	phonebook.welcome();
	while (prompt.compare("EXIT") != 0)
	{
		std::getline(std::cin, prompt);
		if (prompt.compare("ADD") == 0)
			phonebook.add();
		else if (prompt.compare("SEARCH") == 0)
		{
			phonebook.print_contact();
			phonebook.search();
		}
	}
	return(0);
}
