/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:50:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/18 16:23:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	protected :
		const std::string _name;
		bool	_signed;
		const int	_gradeTooSign;
		const int	_gradeTooExec;
	public : 
		AForm();
		virtual ~AForm();
		AForm(std::string name, const int tosigned, const int toexec);
		AForm(AForm const & src);
		AForm & operator=(AForm const & src);


		std::string getName(void) const;
		int getGradeTooSigned(void) const;
		int getGradeTooExec(void) const;
		bool getSigned(void) const;

		void beSigned(Bureaucrat const & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const;
	
	class GradeTooHighException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return ("Grade is too high");
			}
	};
	class GradeTooLowException : public std::exception
	{
		public :
			virtual const char* what() const throw() {
				return ("Grade is too low");
			}
	};
	class FormNotSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {return ("Form not signed");}
	};
};

std::ostream &operator<<(std::ostream &o, AForm const &AForm);

#endif