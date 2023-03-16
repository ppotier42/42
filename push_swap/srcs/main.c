/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:18:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/16 15:21:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_error(char **av)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (av[i][y])
	{
		y = 0;
		while (av[i][y])
		{
			if (ft_isalpha(av[i][y]) == 0)
			{
				ft_printf("Error\n");
				return (0);
			}
			y++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	if (ft_check_error(av) == 1)
		ft_printf("%s", *av);
	return (0);
}
