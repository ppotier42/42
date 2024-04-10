/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:03:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/05 11:24:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::~HumanB(void){
	return ;
}

HumanB::HumanB(std::string const & init): _name(init), _weapon(NULL){
	return;
}

void	HumanB::attack(void) const 
{
	std::cout << this->_name << " attack with their ";
	if (!_weapon)
		std::cout << "hands, and cannot do that !" << std::endl;
	else
		std::cout << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &arme){
		this->_weapon = &arme;
	return ;
}