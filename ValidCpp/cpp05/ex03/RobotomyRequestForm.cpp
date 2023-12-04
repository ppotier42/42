/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:34:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 11:12:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
Form("default", 150, 150), _target("default") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
Form("Robotomy", 72, 45), _target(target)
{
	std::cout << "Intern create Robotomy" << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
Form(src), _target(src._target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	Form::operator=(rhs);
	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if(this->getSigned() == false)
	{
		throw Form::FormNotSignedException();
	}
	try {
		Form::execute(executor);
	}
	catch (std::exception & e) {
		return ;
	}
	int success = std::rand() % 2;
	if (success == 1)
	{
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
		return ;
	}
	std::cout << this->_target << " try to get revenge" << std::endl;
}
