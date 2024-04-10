/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:59:17 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:36:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public virtual ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(std::string name);
	~ScavTrap();

	ScavTrap(const ScavTrap &src);
	ScavTrap & operator=(ScavTrap const &rhs);
	
	std::string getName(void) const;
	int			getEnergy(void) const;

	void	attack(const std::string& target);
	void	guardGate();
};

#endif