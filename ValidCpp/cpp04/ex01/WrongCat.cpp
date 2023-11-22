/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:37:40 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 10:30:06 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Constructor called for WrongCat" << std::endl;
	return ;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src): WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
	return ;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongMeow" << std::endl;
	return ;
}

std::string WrongCat::getType(void) const
{
	return (this->_type);
}