/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:38:19 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/23 14:48:19 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected :
	std::string	_name;
	int			HitPoints;
	int			EnergyPoints;
	int			AttackDamage;

public:
	ClapTrap(void);
	ClapTrap(std::string name);
	~ClapTrap();

	ClapTrap(const ClapTrap &src);
	ClapTrap & operator=(ClapTrap const &rhs);

	std::string getName(void) const;
	int			getEnergy(void) const;
	int			getHp(void) const;

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs);


#endif