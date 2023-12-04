/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:50:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/18 13:04:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
	private :
		const std::string _name;
		bool	_signed;
		const int	_gradeTooSign;
		const int	_gradeTooExec;
	public : 
		Form();
		virtual ~Form();
		Form(std::string name, const int tosigned, const int toexec);
		Form(Form const & src);
		Form & operator=(Form const & src);


		std::string getName(void) const;
		int getGradeTooSigned(void) const;
		int getGradeTooExec(void) const;
		bool getSigned(void) const;

		void beSigned(Bureaucrat const & bureaucrat);
	
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
};

std::ostream &operator<<(std::ostream &o, Form const &form);

#endif