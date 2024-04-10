/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:43:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 11:07:18 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
	public :
		Animal();
		Animal(std::string type);

		Animal(Animal const &src);
		Animal & operator=(Animal const & rhs);
		
		virtual ~Animal();
		virtual void makeSound(void) const;
		std::string getType(void) const;
};


#endif