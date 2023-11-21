/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 12:45:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/31 13:14:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl harl;
	harl.complain("DEBUG");
	harl.complain("ALED");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	return (0);
}