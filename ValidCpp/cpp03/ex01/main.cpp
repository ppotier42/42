/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:00:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 10:35:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "---- ClapTrap ----" << std::endl;
	ClapTrap	a("Clap_A");
	ClapTrap	b(a);
	ClapTrap	c("Clap_C");
	c = a;
	
	std::cout << "1: "; a.attack("b");
	std::cout << "2: "; a.beRepaired(1); //si on peut pas etre reparer
	std::cout << "3: "; a.takeDamage(6); // si on peut prendre des degats
	std::cout << "4: "; a.beRepaired(100); // si on peut etre reparer
	std::cout << "4: "; a.takeDamage(20); // si on meurt
	std::cout << "5: "; a.takeDamage(100); // si on ne peut pas prendre de degat (deja mort)
	std::cout << "6: "; a.beRepaired(3); // si on ne peut plus etre repare (deja mort)
	std::cout << "7: "; a.attack("truc"); // si on ne peut plus attacker (deja mort)
	std::cout << "---- Energy check ----" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << i + 1 << ": "; b.attack("someone");
	}
	b.beRepaired(42);

	std::cout << std::endl << "---- ScavTrap ----" << std::endl;
	ScavTrap	d("Scav_D");
	ScavTrap	e(d);
	ScavTrap	f("Scav_F");
	f = d;

	std::cout << "1: "; d.attack("b");
	std::cout << "2: "; d.guardGate();
	std::cout << "3: "; d.beRepaired(1); //si on peut pas etre reparer
	std::cout << "4: "; d.takeDamage(6); // si on peut prendre des degats
	std::cout << "5: "; d.beRepaired(100); // si on peut etre reparer
	std::cout << "6: "; d.takeDamage(20); // si on meurt
	std::cout << "7: "; d.takeDamage(100); // si on ne peut pas prendre de degat (deja mort)
	std::cout << "8: "; d.beRepaired(3); // si on ne peut plus etre repare (deja mort)
	std::cout << "9: "; d.attack("truc"); // si on ne peut plus attacker (deja mort)
	std::cout << "10: "; d.guardGate();
	std::cout << "---- Energy check ----" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		std::cout << i + 1 << ": "; e.attack("someone");
	}
	e.beRepaired(42);
	e.guardGate();

	std::cout << std::endl << std::endl << "---- Destruction ----" << std::endl;
	return 0;
}