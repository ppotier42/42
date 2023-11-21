/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:03:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/14 14:21:21 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected :
		AAnimal(void);
		std::string type;
	public :
		virtual ~AAnimal(void);
		AAnimal(std::string type);
	
		AAnimal(const AAnimal & src);
		AAnimal & operator=(const AAnimal & rhs);
	
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif