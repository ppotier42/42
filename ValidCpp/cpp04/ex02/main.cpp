/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:29:52 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/22 11:13:47 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main()
{
	AAnimal test;
	Cat basic;
	{
		Cat tmp = basic;
	}
	std::cout << "-----" << std::endl;
	Animal* meta[10];
	for (int i=0; i<5; i++)
	{
		meta[i] = new Dog();
		std::cout << "-----" << std::endl;
	}
	for (int i=5; i<10; i++)
	{
		meta[i] = new Cat();
		std::cout << "-----" << std::endl;
	}
	Animal doggo("doggo");
	doggo.makeSound();
	Animal catto(doggo);
	catto.makeSound();
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Animal " << i << " : ";
		meta[i]->makeSound();
	}
	for (int i = 0; i < 10; i++)
	{
		delete meta[i];
		std::cout << "-----" << std::endl;
	}
}