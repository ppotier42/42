/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:39:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/11 15:23:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Basic Constructor called for WrongAnimal" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	this->type = src.type;
	return ;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs)
{
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}


void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal sound ?" << std::endl;
	return ;
}

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}