/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:43:14 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 10:26:20 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Constructor called for Dog" << std::endl;
	return ;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog" << std::endl;
	return ;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Copy Dog constructor called" << std::endl;
	return ;	
}

Dog & Dog::operator=(Dog const & rhs)
{
	std::cout << "Dog assignement operator called" << std::endl;
	if(this != &rhs)
		this->_type = rhs._type;
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
