/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:51:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/04 20:50:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their ";
	std::cout << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void){
	return ;
}
