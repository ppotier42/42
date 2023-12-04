/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:35:14 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 11:11:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : 
Form("default", 150, 150), _target("default")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : 
Form("ShruberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Intern create ShruberryForm" << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :
Form(src), _target(src._target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	Form::operator=(src);
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
	{
		throw Form::FormNotSignedException();
	}
	try {
		Form::execute(executor);
	}
	catch (std::exception & e) {
		return ;
	}
	std::string filename(this->getTarget() + "_shruberry");
	std::ofstream file;
	file.open(filename.c_str(), std::ios::out);
	if(!file.is_open())
	{
		std::cout << "Couldn't open file" << std::endl;
		return ;
	}
	file << "       _-_\n";
	file << "    /~~   ~~\\\n" ;
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file << "Looks a this binary three\n";
	file << std::endl;
	file.close();
}