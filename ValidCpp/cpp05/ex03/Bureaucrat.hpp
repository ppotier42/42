/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:44:48 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/04 15:32:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Form.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
private:
	std::string const _name;
	int	_grade;
	
	Bureaucrat &operator=(Bureaucrat const & Bureaucrat);
	Bureaucrat(void);
public:
	Bureaucrat(std::string const name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(Bureaucrat const & src);
	
	std::string getName(void) const;
	int getGrade(void) const;
	
	Bureaucrat incrementGrade(void);
	Bureaucrat decrementGrade(void);

	void	signForm(Form &Form) const;
	void	executeForm(Form const & Form) const;

	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char *what() const throw() {return ("Grade Too High !");}
	};
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char *what() const throw() {return ("Grade Too Low");}
	};

};

std::ostream & operator<<(std::ostream & bits, Bureaucrat const & eight);

#endif