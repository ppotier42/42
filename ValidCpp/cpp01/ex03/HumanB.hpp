/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:23:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/30 17:07:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP
# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanB
{
private:
	std::string _name;
	Weapon		*_weapon;
public:
	HumanB(std::string const & init);
	~HumanB(void);
	void	attack(void) const;
	void	setWeapon(Weapon &arme);
};

#endif