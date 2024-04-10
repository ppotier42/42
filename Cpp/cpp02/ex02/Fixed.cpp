/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 15:25:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/01 15:26:42 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _numb(0)
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor Called" << std::endl;
	return ;
}

Fixed::Fixed(int const n) : _numb(n << this->_eight)
{
	// std::cout << "Int constructor called" << std::endl;
	return ;
}

Fixed::Fixed(float const nf) : _numb(roundf(nf * (1 << this->_eight)))
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_numb);
}

Fixed &Fixed::operator=(Fixed const &right)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_numb = right.getRawBits();
	return (*this);
}

Fixed::Fixed(const Fixed &src)
{
	// std::cout << "Copy constructor operator called" << std::endl;
	*this = src;
	return ;
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

//booooooool
bool Fixed::operator>(Fixed const &sup) const
{
	return(this->getRawBits() > sup.getRawBits());
}

bool Fixed::operator<(Fixed const &less) const
{
	return (this->getRawBits() < less.getRawBits());
}

bool Fixed::operator>=(Fixed const &supequal) const
{
	return(this->getRawBits() >= supequal.getRawBits());
}

bool Fixed::operator<=(Fixed const &lessequal) const
{
	return (this->getRawBits() <= lessequal.getRawBits());
}

bool Fixed::operator==(Fixed const &equal) const
{
	return (this->getRawBits() == equal.getRawBits());
}

bool Fixed::operator!=(Fixed const &diff) const
{
	return(this->getRawBits() != diff.getRawBits());
}

//operator
Fixed Fixed::operator+(Fixed const &plus) const
{
	return (Fixed(this->toFloat() + plus.toFloat()));
}

Fixed Fixed::operator-(Fixed const &minus) const
{
	return (Fixed(this->toFloat() - minus.toFloat()));
}

Fixed Fixed::operator*(Fixed const &times) const
{
	return (Fixed(this->toFloat() * times.toFloat()));	
}

Fixed Fixed::operator/(Fixed const &div) const
{
	return(Fixed(this->toFloat() / div.toFloat()));
}

// ++ --

Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);
	++(*this);
	return cpy;
}

Fixed &Fixed::operator++(void)
{
	++(this->_numb);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--(this->_numb);
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);
	--(*this);
	return cpy;
}

// min and max

Fixed &Fixed::min(Fixed &arg1, Fixed &arg2)
{
	if (arg1.getRawBits() < arg2.getRawBits())
		return (arg1);
	return (arg2);	
}

Fixed const &Fixed::min(Fixed const &arg1, Fixed const &arg2)
{
	if (arg1.getRawBits() < arg2.getRawBits())
		return (arg1);
	return (arg2);	
}

Fixed &Fixed::max(Fixed &arg1, Fixed &arg2)
{
	if (arg1.getRawBits() > arg2.getRawBits())
		return (arg1);
	return (arg2);
}

Fixed const &Fixed::max(Fixed const &arg1, Fixed const &arg2)
{
	if (arg1.getRawBits() > arg2.getRawBits())
		return (arg1);
	return (arg2);
}