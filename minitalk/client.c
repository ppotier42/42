/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:09:12 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/30 22:14:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (0x01 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	pid = ft_atoi_mini(av[1]);
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			ft_send(pid, av[2][i]);
			i++;
		}
	}
	else
		ft_putstr("Error\n");
	ft_send(pid, '\n');
	return (0);
}
