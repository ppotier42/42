/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:39:18 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:33:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("Default FragTrap")
{
	EnergyPoints = 100;
	HitPoints = 100;
	AttackDamage = 30;
	std::cout << "Basic FragTrap constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap constructor for " << this->_name << std::endl;
	this->EnergyPoints = 100;
	this->HitPoints = 100;
	this->AttackDamage = 30;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->HitPoints = rhs.HitPoints;
		this->AttackDamage = rhs.AttackDamage;
		this->EnergyPoints = rhs.EnergyPoints;
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	if (this->HitPoints <= 0)
		std::cout << this->_name << " can't to a HighFive because he is dead" << std::endl;
	else if (this->EnergyPoints <= 0)
		std::cout << this->_name << " can't to a HighFive because he is tired" << std::endl;	
	else
		std::cout << "Fragtrap " << this->_name << " want a HighFive !" << std::endl;
	return ;
}

std::ostream & operator<<(std::ostream & o, FragTrap const & rhs) {
	o << rhs.getName()<< " with " << rhs.getHp() << " HP and " << rhs.getEnergy() << " energy points." << std::endl; 
	return (o);
}