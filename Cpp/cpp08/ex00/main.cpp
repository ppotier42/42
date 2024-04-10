/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:53:53 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/01 12:59:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

#include <list>
#include <vector>
#include <map>

int main(void)
{
	{
	std::vector<int> vec(43);
	vec.push_back(10);
	vec.push_back(4);
	vec.push_back(6);
	vec.push_back(45);
	vec.push_back(61);
	easyfind(vec, 4);
	std::cout << "-------" << std::endl;
	easyfind(vec, 1);
	std::cout << "-------" << std::endl;
	easyfind(vec, 61);
	std::cout << "-------" << std::endl;
	easyfind(vec, 43);
	std::cout << "-------" << std::endl;
	easyfind(vec, -4);
	std::cout << "-------" << std::endl;
	}
	std::cout << "list" << std::endl;
	std::cout << "-------" << std::endl;
	{
		std::list<int> lst(5);
		lst.push_back(10);
		lst.push_front(4);
		lst.push_back(6);
		lst.push_back(45);
		lst.push_back(61);
		easyfind(lst, 4);
		std::cout << "-------" << std::endl;
		easyfind(lst, 1);
		std::cout << "-------" << std::endl;
		easyfind(lst, 61);
		std::cout << "-------" << std::endl;
		easyfind(lst, 43);
		std::cout << "-------" << std::endl;
		easyfind(lst, -4);
		std::cout << "-------" << std::endl;
	}
	return 0;
}