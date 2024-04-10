/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:00:09 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 14:46:50 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Base.hpp"

Base *generate(void)
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	std::cout << c << ": Created" << std::endl;
	switch (c)
	{
	case 'A' :
		return new A;
	case 'B' :
		return new B;
	case 'C' :
		return new C;
	}
	return NULL;
}

static void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	return ;
}

static void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &bc) {
		try {
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
	catch (std::exception &bc) {
		try {
			C &c = dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
		}
		catch (std::exception &bc) {
			std::cout << "Error" << std::endl;
		}
	}
	}
}
/*
dynamic_cast est un opérateur de conversion de type en C++ utilisé spécifiquement 
pour la manipulation de types polymorphiques dans une hiérarchie 
de classes (c'est-à-dire des classes qui ont au moins une fonction virtuelle). 
Il est principalement utilisé pour effectuer des conversions de 
types sûres et vérifiées à l'exécution.
dynamic_cast ne peut être utilisé qu'avec des 
types polymorphiques (c'est-à-dire avec au moins une fonction virtuelle).*/
int main (void)
{
	Base *base = generate();
	std::cout << "----------" << std::endl;
	identify(base);
	std::cout << "----------" << std::endl;
	identify(*base);
	std::cout << "----------" << std::endl;
	delete base;	
	return 0;
}