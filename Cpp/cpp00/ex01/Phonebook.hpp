/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:56:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/28 17:33:47 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PHONEBOOK_HPP
# define PHONEBOOK_HPP 

# include <string>
# include <iostream>
# include <cstdio>
# include <iomanip>
#include "Contact.hpp"

using namespace std;

class Phonebook
{
private:
	Contact _contact[8];
public:
	void	welcome();
	void	add();
	void	print_contact() const;
	void	search() const;
	int	_readInput() const;
};


int main(void);

#endif