/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:44:13 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/29 14:20:03 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScalarConverte.hpp"

/*	static-casting :
	Il peut être utilisé pour convertir
	des types primitifs (comme int en double, etc.)
	s'ils sont considérés comme convertibles sans perte de données.
	Ne verifie pas la validité a la conversion contrairement a Dynamic_cast.
*/
int main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverte::convert(av[1]);
	return 0;
}