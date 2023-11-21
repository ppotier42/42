/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:39:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/14 22:00:18 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>

void	ft_upper(char *str)
{
	for(int i = 0; str[i]; i++)
	std::cout << (char) toupper(str[i]);
}

int	main(int ac, char **av)
{
	int i = 0;
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (++i < ac)
			ft_upper(av[i]);
	}
	std::cout << '\n';
	return(0);
}
