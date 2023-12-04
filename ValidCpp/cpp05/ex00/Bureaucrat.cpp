/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:56:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/27 11:25:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Basic Constructor called for Bureaucrat" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	return ;
}

std::string Bureaucrat::getName(void) const
{
	return(this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

Bureaucrat Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	++(this->_grade);
	return (*this);
}

Bureaucrat Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	--(this->_grade);
	return (*this);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if(this != &bureaucrat)
		this->_grade = bureaucrat.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &Bureaucrat)
{
	o << Bureaucrat.getName() << ", bureaucrat grade : " << Bureaucrat.getGrade() << std::endl;
	return o;
}
