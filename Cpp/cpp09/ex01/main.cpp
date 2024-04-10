/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:10:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/12/20 10:58:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>
#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac == 2) {
		RPN rpn;
		std::string input = av[1];
		rpn.doOperation(input);
	}
	else {
		std::cerr << "Error\n";
	}
	return 0;
}