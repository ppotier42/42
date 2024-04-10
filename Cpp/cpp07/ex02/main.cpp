/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:02:50 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/30 16:40:08 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) 
{
	// {
	// 	int *a = new int();
	// 	std::cout << *a << std::endl;
	// 	delete a;
	// }
	Array<int> a;
	std::cout << "-------------\n";
	std::cout << a.size() << std::endl;
	std::cout << "-------------\n";
	Array<int> b(5);
	for (int i = 0; i < 5; i++) {
		b[i] = i; 
		std::cout << b[i] << std::endl;
	}
	std::cout << "-------\n size: ";
	std::cout << static_cast<int>(b.size());
	std::cout << "\n-------\n";
	try {
		b[7] = 6;
	} catch (const std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}