/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:03:48 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:30:29 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0) 
{
	std::cout << "Basic contructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	this->AttackDamage = 0;
	this->HitPoints = 10;
	this->EnergyPoints = 10;
	std::cout << "ClapTrap constructor called for " << this->_name << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called -> ";
	std::cout << this->_name << " is dead." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
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

std::string ClapTrap::getName(void) const
{
	return this->_name;
}

int	ClapTrap::getHp(void) const
{
	return this->HitPoints;
}

int	ClapTrap::getEnergy(void) const
{
	return this->EnergyPoints;
}


void	ClapTrap::attack(const std::string& target)
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
	std::cout << "Claptrap " << this->_name << " attack " << target;
	std::cout << ", causing " << this->AttackDamage << " points of damage." << std::endl;
	this->EnergyPoints -= 1;
	std::cout << this->EnergyPoints << " Energy points left for " << this->_name << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoints <= 0)
	{
		std::cout << this->_name << " is dead omg !" << std::endl;
		return ;
	}
	else
	{
		std::cout << this->_name << " has taken " << amount << " damage !" << std::endl;
		this->HitPoints -= amount;
		std::cout << this->_name << " has " << this->HitPoints << " Hitpoints left !" << std::endl;	
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
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
	else if (this->HitPoints >= 10)
	{
		std::cout << this->_name << " have already all his life" << std::endl;
		return ;
	}
	else if (amount > 10)
	{
		std::cout << "Life of " << this->_name << " is only 10" << std::endl;
		return ;
	}
	std::cout << this->_name << " Regaining " << amount << " of HitPoints" << std::endl;
	this->HitPoints += amount;
	std::cout << this->_name << " Have " << this->HitPoints << " Hitpoints left !" << std::endl;
	this->EnergyPoints -= 1;
	std::cout << this->EnergyPoints << " Energy points left for " << this->_name << std::endl;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs) {
	o << rhs.getName()<< " with " << rhs.getHp() << " HP and " << rhs.getEnergy() << " energy points." << std::endl; 
	return (o);
}