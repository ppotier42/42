/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:52 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/21 12:39:18 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	const Animal* meta = new Animal();
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	
	std::cout << std::endl << "Wrong classes:" << std::endl;
	const WrongAnimal* x = new WrongCat();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	std::cout << x->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	x->makeSound();
	wrongmeta->makeSound();

	delete(i);
	delete(j);
	delete(meta);
	delete(x);
	delete(wrongmeta);
	return (0);
}