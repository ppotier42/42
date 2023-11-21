/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:56:16 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:35:50 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONTRAP_HPP
# define DIAMONTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private :
		std::string _name;
	public :
		DiamondTrap(void);
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap & operator=(DiamondTrap const & rhs);

		void	whoAmI();
};

std::ostream & operator<<(std::ostream & o, DiamondTrap const & rhs);

#endif