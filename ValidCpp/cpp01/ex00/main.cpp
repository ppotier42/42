/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:19:48 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/18 18:09:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Foo = newZombie("Foo");
	Foo->announce();
	randomChump("Fight");
	delete(Foo);
	return (0);
}