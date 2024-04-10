/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:51:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/18 15:09:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Activity"), _gradeTooExec(1), _gradeTooSign(1), _signed(false) {}

Form::Form(std::string name, const int tosigned, const int toexec) : _name(name), _gradeTooExec(toexec), _gradeTooSign(tosigned), _signed(false)
{
	if (tosigned < 1 || toexec < 1)
		throw Form::GradeTooLowException();
	if (tosigned > 150 || toexec > 150)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
	return ;
}

Form::Form(Form const & src) : _name(src._name), _gradeTooExec(src._gradeTooExec), _gradeTooSign(src._gradeTooSign), _signed(src._signed)
{
}

std::string Form::getName(void) const
{
	return(this->_name);
}

int Form::getGradeTooSigned(void) const
{
	return(this->_gradeTooSign);
}

int Form::getGradeTooExec(void) const
{
	return(this->_gradeTooExec);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeTooSigned())
	{
		throw Form::GradeTooLowException();
	}
	else
		this->_signed = true;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeTooExec)
	{
		throw Form::GradeTooLowException();
		return ;
	}
}


Form & Form::operator=(Form const & src) {
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, Form const &Form)
{
	o << Form.getName() << "Need grade" << Form.getGradeTooSigned()
	 << " too be signed, and " << Form.getGradeTooExec() << " grade to be execute" << std::endl;
	return o;
}

