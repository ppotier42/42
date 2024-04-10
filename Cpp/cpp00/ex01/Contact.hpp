/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 19:28:53 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 16:44:31 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private:
		std::string _firstname;
		std::string _lastname;
		std::string	_nickname;
		std::string _number;
		std::string	_secret;
		std::string	_getInput(std::string str) const;
		int			index;
	public :
		Contact();
		~Contact();
		void	add_contact(void);
		void	set_index(int index);
		void	_printsearch(int index) const;
		std::string _printlen(std::string str) const;
		void		print_contact(int index) const;
};


#endif