/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:51:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 10:26:06 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
	return ;
}

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Constructor called for " << this->_type << std::endl;
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	return ;	
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if(this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->_type << " Meow" << std::endl;
	return ;
}

std::string Cat::getType(void) const
{
	return (this->_type);
}
