/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:33:09 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 11:12:56 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
Form("default", 150, 150), _target("default")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
Form("Presidential", 25, 5), _target(target)
{
	std::cout << "Intern create Presidential" << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
Form(src), _target(src._target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	Form::operator=(rhs);
	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
	{
		throw Form::FormNotSignedException();
	}
	try {
		Form::execute(executor);
	}
	catch (std::exception & e)
	{
		return ;
	}
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}