/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:58:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/27 11:28:02 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>

int main() {
	std::cout << "---------------------" << std::endl;
	try {
	Bureaucrat b("Bureaucrat", -1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try {
	Bureaucrat b("Bureaucrat", 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	Bureaucrat b("Bureaucrat", 1);
	try {
		b.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	Bureaucrat b2("Bureaucrat", 150);
	try {
		b2.decrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	Bureaucrat Hermes("Hermes Conrad", 1);
	std::cout << Hermes << std::endl;
	Hermes.decrementGrade();
	std::cout << Hermes << std::endl;
	for(int i = 0; i < 50; i++)
	{
			Hermes.decrementGrade();
			std::cout << Hermes << std::endl;
	}
	return (0);
}
