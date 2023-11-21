/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:26:46 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:41:08 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	return ;
}

DiamondTrap::~DiamondTrap()
{
	return ;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_Trap"), FragTrap(name + "_clap_Frag"), ScavTrap(name + "_clap_Scav"), _name(name)
{
	std::cout << "Constructor Diamond called" << std::endl;
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;
	return ;
}

DiamondTrap & DiamondTrap::operator=(DiamondTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->HitPoints = rhs.HitPoints;
		this->AttackDamage = rhs.AttackDamage;
		this->EnergyPoints = rhs.EnergyPoints;
	}
	std::cout << "Operator Diamond = called" << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name " << this->_name << std::endl;
	std::cout << "ScavTrap name " << this->ClapTrap::_name << std::endl;
	std::cout << "FragTrap name " << this->FragTrap::_name << std::endl;
	return ;
}

// std::ostream & operator<<(std::ostream & o, DiamondTrap const & rhs) {
// 	o << rhs.DiamondTrap::getName() << " with " << rhs.DiamondTrap::getHp() \
// 	 <<" HP and " << rhs.DiamondTrap::getEnergy() << " energy points." << std::endl;
// 	return (o);
// }