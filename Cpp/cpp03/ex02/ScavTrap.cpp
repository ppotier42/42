/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:04 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 10:48:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "Basic SvacTrap constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap Constructor for called ->" << this->_name << " created !" << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Desctructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
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

std::string ScavTrap::getName(void) const
{
	return this->_name;
}

int	ScavTrap::getEnergy(void) const
{
	return this->EnergyPoints;
}


void	ScavTrap::guardGate()
{
	if (this->HitPoints <= 0)
	{
		std::cout << this->_name << " is already dead !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " have enter mode Gate Keeper" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoints == 0)
	{
		std::cout << "Energy points are too low" << std::endl;
		return ;
	}
	else if (this->HitPoints <= 0)
	{
		std::cout << this->_name << " is already dead !" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->AttackDamage << " points of damage." << std::endl;
	this->EnergyPoints -= 1;
	std::cout << this->EnergyPoints << " Energy points left for " << this->_name << std::endl;
	return ;
}

std::ostream & operator<<(std::ostream & o, ScavTrap const & rhs) {
	o << rhs.getName()<< " with " << rhs.getHp() << " HP and " << rhs.getEnergy() << " energy points." << std::endl; 
	return (o);
}