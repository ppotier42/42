/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:44:31 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/30 13:46:21 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_write(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar(i);
		bit = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	while (ac == 1)
	{
		signal(SIGUSR1, ft_write);
		signal(SIGUSR2, ft_write);
		pause();
	}
	return (0);
}