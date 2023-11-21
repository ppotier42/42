/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:49:29 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/14 14:26:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain* _brain;
public:
	Cat(void);
	~Cat();
	
	Cat(Cat const & src);
	Cat & operator=(Cat const & rhs);

	void makeSound(void) const;
	std::string getType(void) const;
};


#endif