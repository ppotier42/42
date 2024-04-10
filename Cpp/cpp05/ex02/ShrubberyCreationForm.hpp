/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:35:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/04 10:48:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUbBERYCREATIONFORM_HPP
#define SHRUbBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string _target;
		ShrubberyCreationForm();
	public :
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

		void	execute(Bureaucrat const & executor) const;

		std::string getTarget(void) const;
};

#endif