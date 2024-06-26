/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:47:16 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 10:28:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Basic Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type) 
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal" << std::endl;
	return ;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Animal & Animal::operator=(Animal const & rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << " Doesn't make sound" << std::endl;
	return ;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}