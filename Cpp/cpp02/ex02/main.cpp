/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 14:52:06 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/23 10:35:27 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << "---------" << std::endl;
	std::cout << --a << std::endl;
	std::cout << "---------" << std::endl;

	std::cout << b << std::endl;
	std::cout << "---------" << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "---------" << std::endl;
	return 0;
}