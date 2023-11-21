/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:15:01 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/01 15:29:42 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_numb;
	const static int _eight = 8;
public:
	
	Fixed(void);
	Fixed(int const n);
	Fixed(float const nf);
	Fixed(const Fixed &src);
	~Fixed();

	Fixed &operator=(Fixed const &right);

	void setRawBits(int const raw);
	int	getRawBits(void) const;
	int	toInt(void) const;
	float toFloat(void) const;

	bool operator>(Fixed const &sup) const;
	bool operator<(Fixed const &less) const;
	bool operator>=(Fixed const &supequal) const;
	bool operator<=(Fixed const &lessequal) const;
	bool operator==(Fixed const &equal) const;
	bool operator!=(Fixed const &diff) const;

	Fixed operator+(Fixed const &plus) const;
	Fixed operator-(Fixed const &minus) const;
	Fixed operator*(Fixed const &times) const;
	Fixed operator/(Fixed const &div) const;

	Fixed operator++(int);
	Fixed operator--(int);
	Fixed &operator++(void);
	Fixed &operator--(void);

	static Fixed &min(Fixed &arg1, Fixed &arg2);
	static Fixed const &min(Fixed const &arg1, Fixed const &arg2);
	static Fixed &max(Fixed &arg1, Fixed &arg2);
	static Fixed const &max(Fixed const &arg1, Fixed const &arg2);
};

std::ostream & operator<<(std::ostream & bits, Fixed const & eight);


#endif