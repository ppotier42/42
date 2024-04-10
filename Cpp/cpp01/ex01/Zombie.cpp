/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:49:07 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/21 15:59:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl;
	return ;
}

void Zombie::setName(std::string name) { _name = name; }

void Zombie::announce()
{
	std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}