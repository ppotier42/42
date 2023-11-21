/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:51:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/14 12:34:53 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::~Cat()
{
	std::cout << "Destructor called for Cat" << std::endl;
	delete this->_brain;
	return ;
}

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Constructor called for " << this->type << std::endl;
	return ;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	return ;
}

Cat & Cat::operator=(Cat const & rhs)
{
	std::cout << "Cat assignement operator called" << std::endl;
	if(this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << this->type << " Meow" << std::endl;
	return ;
}

std::string Cat::getType(void) const
{
	return (this->type);
}
