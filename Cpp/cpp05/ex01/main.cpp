/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:58:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/27 11:32:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
// #include "Form.hpp"

int main() {
	std::cout << "---------------------" << std::endl;
	try {
		Form f("Form", -1, 0);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	try {
		Form f3("Form", 1, 160);
		std::cout << f3 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------" << std::endl;
	Bureaucrat b("Bureaucrat 1", 75);
	std::cout << b ;
	std::cout << "---------------------" << std::endl;
	Form f1("Form1", 1, 150);
	Form f2("Form2", 75, 150);
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	b.signFrom(f1);
	b.signFrom(f2);
	return (0);
}
