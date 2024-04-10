/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:49:20 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/21 16:19:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRTDBG_MAP_ALLOC
#include "Zombie.hpp"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int I = 5;
	Zombie *zombies = zombieHorde(I, "Zombie n'");
	for (int j = 0; j < I; j++)
		zombies[j].announce();
	delete[] zombies;
	return (0);
}