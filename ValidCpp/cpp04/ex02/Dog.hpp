/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:20:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/14 14:26:19 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{	
	private: 
		Brain* _brain;
	public :
	Dog(void);
	~Dog();

	Dog(Dog const & src);
	Dog & operator=(Dog const & rhs);
	
	void makeSound(void) const;
	std::string getType(void) const;
};


#endif