/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:51:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/04 15:27:45 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Activity"), _gradeTooExec(1), _gradeTooSign(1), _signed(false) {}

AForm::AForm(std::string name, const int tosigned, const int toexec) : _name(name), _gradeTooExec(toexec), _gradeTooSign(tosigned), _signed(false)
{
	if (tosigned < 1 || toexec < 1)
		throw AForm::GradeTooLowException();
	if (tosigned > 150 || toexec > 150)
		throw AForm::GradeTooHighException();
}

AForm::~AForm()
{
	return ;
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeTooExec(src._gradeTooExec), _gradeTooSign(src._gradeTooSign), _signed(src._signed)
{
}

std::string AForm::getName(void) const
{
	return(this->_name);
}

int AForm::getGradeTooSigned(void) const
{
	return(this->_gradeTooSign);
}

int AForm::getGradeTooExec(void) const
{
	return(this->_gradeTooExec);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeTooSigned())
	{
		throw AForm::GradeTooLowException();
	}
	else
		this->_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeTooExec)
	{
		throw AForm::GradeTooLowException();
		return ;
	}
}


AForm & AForm::operator=(AForm const & src) {
	if (this != &src)
		this->_signed = src._signed;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, AForm const &AForm)
{
	o << AForm.getName() << "Need grade" << AForm.getGradeTooSigned()
	 << " too be signed, and " << AForm.getGradeTooExec() << " grade to be execute" << std::endl;
	return o;
}

