/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:15:01 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/01 14:31:49 by ppotier          ###   ########.fr       */
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
	
	Fixed(const Fixed &src);
	Fixed(void);
	Fixed(int const n);
	Fixed(float const nf);
	~Fixed();

	Fixed &operator=(Fixed const &right);
	float toFloat(void) const;
	int	toInt(void) const;
	void setRawBits(int const raw);
	int	getRawBits(void) const;
};

std::ostream & operator<<(std::ostream & bits, Fixed const & eight);


#endif