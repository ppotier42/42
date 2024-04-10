/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:56:36 by ysoroko           #+#    #+#             */
/*   Updated: 2023/10/05 11:19:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "iostream"

int	main(void)
{
	Intern	someRandomIntern;
	Form*	rrf;

	try 
	{
		rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Target");
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		rrf = someRandomIntern.makeForm("presidential request", "Target");
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		rrf = someRandomIntern.makeForm("presidl request", "Target");
	}
	catch (std::exception & e) 
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}	