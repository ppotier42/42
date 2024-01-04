/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:21:25 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/18 14:05:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>


int main(int ac, char **av)
{
	if (ac == 2)
	{
		Bitcoin btc("data.csv");
		btc.checkInput(av[1]); 
	}
	else
		std::cout << "Error: please send a file\n";
	return 0;
}