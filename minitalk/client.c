/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:09:12 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/13 11:17:13 by ppotier          ###   ########.fr       */
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
		usleep(200);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 1)
		ft_putstr_error("Usage : ./client PID Message\n");
	if (ac == 2)
		ft_putstr_error("Error, not enough arguments\n");
	pid = ft_atoi_mini(av[1]);
	if (ac == 3)
	{
		while (av[2][i] != '\0')
		{
			ft_send(pid, av[2][i]);
			i++;
		}
		ft_send(pid, '\n');
	}
	else
		ft_putstr_error("Error\n");
	return (0);
}
