/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:34:33 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 13:27:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _numb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor Called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_numb);
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_numb = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor operator called" << std::endl;
	*this = src;
	return ;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_numb = raw;
}