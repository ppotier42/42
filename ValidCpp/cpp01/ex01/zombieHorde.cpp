/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombiehorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:48:06 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/21 16:18:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	std::stringstream ss;
	for(int i = 0; i < N; i++)
	{
		zombies[i].setName("Zombie number " + to_string(i));
	}
	return (zombies);
}