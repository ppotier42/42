/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:48:01 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/31 13:15:50 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
			(this->*f[i])();
		i++;
	}
}

void	Harl::debug(void)
{
	std::cout << "debug :: love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info :: I cannot believe adding extra bacon costs more money." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning :: I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error(void)
{
	std::cout << "error :: This is unacceptable ! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}