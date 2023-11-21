/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:38:03 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/11 15:22:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
	public :
		WrongCat();
		~WrongCat();

		WrongCat(WrongCat const & src);
		WrongCat & operator=(WrongCat const & rhs);

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif