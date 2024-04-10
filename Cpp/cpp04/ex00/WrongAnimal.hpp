/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:38:47 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 10:24:56 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
	protected : 
	std::string _type;
	public :
	WrongAnimal();
	~WrongAnimal();
	WrongAnimal(std::string type);

	WrongAnimal(WrongAnimal const & src);
	WrongAnimal & operator=(WrongAnimal const & rhs);
	
	void makeSound(void) const;
	std::string getType(void) const;
};

#endif