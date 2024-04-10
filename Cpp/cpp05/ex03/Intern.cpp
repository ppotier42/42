/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 11:21:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <string>
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern(void)
{
	this->_formRequest[0] = "robotomy request";
	this->_formRequest[1] = "presidential request";
	this->_formRequest[2] = "shrubbery request";
	return ;
}

Intern::~Intern()
{
	return ;
}

Form*	Intern::makeForm(std::string const s1, std::string const s2)
{
	int ret = 3;
	Form *t_form;

	for(int i = 0; i < 3; i++)
	{
		if (this->_formRequest[i] == s1)
			ret = i;
	}
	switch (ret)
	{
	case 0:
		t_form = new RobotomyRequestForm(s2);
			break;
	case 1:
		t_form = new PresidentialPardonForm(s2);
			break;
	case 2:
		t_form = new ShrubberyCreationForm(s2);
			break ;
	default :
		throw NoFormFind();
	}
	return (t_form);
}

Intern &Intern::operator=(Intern const & intern)
{
	if (this != &intern)
		return *this;
	return (*this);
}
