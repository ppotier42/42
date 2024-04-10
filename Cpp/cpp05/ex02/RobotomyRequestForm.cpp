/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:34:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/18 16:19:30 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
AForm("default", 150, 150), _target("default") {
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
AForm("Robotomy", 72, 45), _target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) :
AForm(src), _target(src._target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
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
		throw AForm::FormNotSignedException();
	}
	try {
		AForm::execute(executor);
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
