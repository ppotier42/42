/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2023/11/27 12:50:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat  b3("Bureaucrat3", 3);
	AForm		*f3 = new PresidentialPardonForm("President");

	std::cout << b3 << std::endl;
	b3.executeForm(*f3);
	std::cout << b3 << std::endl;
	b3.signForm(*f3);
	b3.executeForm(*f3);
	delete f3;

	return (0);
}