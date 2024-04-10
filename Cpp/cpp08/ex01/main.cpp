/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:57:09 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/01 16:37:38 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <string>
#include <iostream>

//  try and catch dans le span
// sinon fonctionne pour longest;
int main (void)
{
	{	
		Span sp = Span(2);
		try {
			sp.addNumber(45);
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		try {
			sp.addNumber(45);
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		try {
			sp.addNumber(53);
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << "------------------" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	try {
	std::vector<int> vect;
	vect.push_back(10);
	vect.push_back(100);
	vect.push_back(20);
	vect.push_back(10);
	vect.push_back(100);
	vect.push_back(20);
	sp.addNumber(vect);
	std::cout << sp.shortestSpan() << "\n";
	std::cout << sp.longestSpan() << "\n";
	}
	catch ( std::exception &e) {
		std::cout << e.what() << "\n";
	}
	return 0;
}