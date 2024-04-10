/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:05:31 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/14 14:26:44 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "Basic Animal constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : type(type) 
{
	std::cout << "Animal constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor called for AAnimal" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.type;
	return (*this);
}

void	AAnimal::makeSound(void) const
{
	std::cout << this->type << " Doesn't make sound" << std::endl;
	return ;
}

std::string AAnimal::getType(void) const
{
	return (this->type);
}