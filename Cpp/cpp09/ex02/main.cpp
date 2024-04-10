/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:42:10 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/21 15:29:48 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <vector>
#include <sstream>
#include <string>
#include <chrono>
#include <algorithm>
#include <iostream>
#include <limits>

bool	storeInput(char **av, std::deque<unsigned int> *deq, std::vector<unsigned int> *vec)
{
	std::string			input(av[1]);
	std::stringstream	ss;
	unsigned int		nb;

	for (int i = 1; av[i] != NULL; i++) {
		input = av[i];
		if (input.find_first_not_of("0123456789") != std::string::npos)
			return false;
		if (input.size() >= 10 && input.compare("4294967295") > 0)
			return false;
		ss << av[i] << " ";
	}
	while (ss >> nb) {
		deq->push_back(nb);
		vec->push_back(nb);
	}
	return true;
}

void	printContentUnsorted(char **av)
{
	std::cout << "Before:\t";
	for (int i = 1; av[i] != NULL; i++) {
		std::cout << av[i] << " ";
	}
	std::cout << std::endl;
}

void	printSorted(std::vector<unsigned int> vec)
{
	std::cout << "After:\t";
	for (std::vector<unsigned int>::iterator i = vec.begin(); i != vec.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
}

// void	printSorted(std::deque<unsigned int> deq)
// {
// 	std::cout << "After:\t";
// 	for (std::deque<unsigned int>::iterator i = deq.begin(); i != deq.end(); i++)
// 		std::cout << *i << " ";
// 	std::cout << std::endl;
// }

int main(int ac, char **av)
{
	std::deque<unsigned int> deq;
	std::vector<unsigned int> vec;
	if (ac <= 2) {
		std::cerr << "Not enough arguments" << std::endl;
		return 0;
	}
	else
	{
		if (storeInput(av, &deq, &vec) == false) {
			std::cerr << "Wrong parameter" << std::endl;
			return 0;
		}
	}
	printContentUnsorted(av);

	std::chrono::high_resolution_clock::time_point start;
	std::chrono::high_resolution_clock::time_point end;
	std::chrono::high_resolution_clock::time_point startDeq;
	std::chrono::high_resolution_clock::time_point endDeq;
	std::chrono::nanoseconds time;
	std::chrono::nanoseconds timeDeq;

	start = std::chrono::high_resolution_clock::now();
	PmergeMe vecmerge(vec);
	end = std::chrono::high_resolution_clock::now();
	time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[vector] : " << time.count() << " ns\n";


	// deque
	startDeq = std::chrono::high_resolution_clock::now();
	PmergeMe deqmerge(deq);
	endDeq = std::chrono::high_resolution_clock::now();
	timeDeq = std::chrono::duration_cast<std::chrono::nanoseconds>(endDeq - startDeq);
	std::cout << "Time to process a range of " << vec.size() << " elements with std::[deque] : " << timeDeq.count() << " ns\n";
	if (timeDeq < time)
		std::cout << "std::Deque WINS !" << std::endl;
	else
		std::cout << "std::vector WINS !" << std::endl;
	return 0;
}