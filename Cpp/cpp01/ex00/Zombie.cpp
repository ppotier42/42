/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:24:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 18:08:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " is dead" << std::endl;
	return ;
}

void Zombie::announce(void) const
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}