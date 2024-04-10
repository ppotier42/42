/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:00:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 11:29:31 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "---------------\tCreation ClapTrap" << std::endl;
	ClapTrap	a("CLAP_qqn");
	ClapTrap	b(a);
	ClapTrap	c = a;
	
	std::cout << std::endl << "---------------\tCreation ScavTrap" << std::endl;
	ScavTrap	x("SCAV_qqch");
	ScavTrap	y(x);
	ScavTrap	z = x;
	
	std::cout << std::endl << "---------------\tCreation FragTrap" << std::endl;
	FragTrap	m("FRAG_ola");
	FragTrap	n(m);
	FragTrap	o = m;

	std::cout << std::endl << "---------------\tCreation DiamondTrap" << std::endl;
	DiamondTrap	q("DIAM_pepito");
	DiamondTrap	w(q);
	DiamondTrap	e = w;

	std::cout << std::endl << std::endl << "---------------\tOperation ClapTrap" << std::endl;
	a.attack("SOMEONE");
	b.takeDamage(10);
	c.beRepaired(3);
	std::cout << std::endl << "---------------\tOperation ScavTrap" << std::endl;;
	x.attack("SOMEONE");
	y.takeDamage(10);
	y.guardGate();
	z.beRepaired(3);
	// z.highFivesGuys();
	std::cout << std::endl << "---------------\tOperation FragTrap" << std::endl;;
	m.attack("SOMEONE");
	n.takeDamage(4);
	o.highFivesGuys();
	// o.guardGate();
	std::cout << std::endl << "---------------\tOperation DiamondTrap" << std::endl;;
	q.attack("SOMEONE");
	q.whoAmI();
	q.highFivesGuys();
	// q.beRepaired(2);
	std::cout << std::endl << "---------------\tDestruction" << std::endl;
	return 0;
}