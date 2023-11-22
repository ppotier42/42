/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:43:14 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 11:00:31 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Constructor called for Dog" << std::endl;
	_brain = new Brain();
	return ;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;
	delete this->_brain;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	return ;
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if(this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << " Woaf" << std::endl;
	return ;
}

std::string Dog::getType(void) const
{
	return (this->_type);
}
