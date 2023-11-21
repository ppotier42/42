/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:34:33 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/01 14:33:47 by ppotier          ###   ########.fr       */
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

Fixed::Fixed(int const n) : _numb(n << this->_eight)
{
	std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nf) : _numb(roundf(nf * (1 << this->_eight)))
{
	std::cout << "Float constructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_numb);
}

Fixed &Fixed::operator=(Fixed const &right)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_numb = right.getRawBits();
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

float	Fixed::toFloat(void) const
{
	return ((float)this->_numb / (float)(1 << this->_eight));
}

std::ostream & operator<<(std::ostream & bits, Fixed const & eight)
{
	bits << eight.toFloat();
	return (bits);
}

int Fixed::toInt(void) const
{
	return(this->_numb >> this->_eight);
}