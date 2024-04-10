/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:54:20 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/30 17:08:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string const & init) : _weapon(init){
	return ;
}

std::string const & Weapon::getType(void) const {
	return this->_weapon;
}

void	Weapon::setType(std::string type){
	this->_weapon = type;
	return ;
}

Weapon::~Weapon(void){
	return ;
}