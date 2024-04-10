/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverte.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 22:43:29 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 11:23:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP
# include <string>
# include <iostream>

class ScalarConverte
{
	private :
		ScalarConverte(void);
		virtual ~ScalarConverte(void);
		ScalarConverte(const ScalarConverte& src);
	public:
		static void convert(const char *input);
		class NonDisplayableExecp : public std::exception {
			public : 
				virtual const char *what() const throw() {
					return ("Non Displayable");
				}
		};
		class ImpossibleCast : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("Impossible");
				}
		};
		class IntMinMaxExec : public std::exception {
			public :
				virtual const char *what() const throw() {
					return ("Too high/low");
				}
		};
		ScalarConverte& operator=(const ScalarConverte &rhs);
};

std::ostream& operator<<(std::ostream& os, const ScalarConverte& src);

#endif