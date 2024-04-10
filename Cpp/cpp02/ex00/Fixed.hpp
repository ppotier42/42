/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:31:56 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 13:27:40 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
private:
	int	_numb;
	const static int _eight = 8;
public:
	
	int	getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed(const Fixed &src);
	Fixed &operator=(Fixed const &src);
	Fixed();
	~Fixed();
};


#endif