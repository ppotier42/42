/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 13:09:12 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/15 14:04:08 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void	ft_putstr(char *s);
int		ft_atoi_mini(char *str, int *res);
void	ft_putchar(char c);

void	send_char(int pid, char c)
{
	int	i;
	int	shift;

	i = 7;
	while (i >= 0)
	{
		shift = 1 << (i);
		if (c & shift)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	send_char(pid, str[i]);
}

int	send(int pid, char *str)
{
	if (kill(pid, 0) == -1)
	{
		ft_putstr("Invalid PID\n");
		return (1);
	}
	else
	{
		if (pid == 0)
		{
			ft_putstr("Invalid PID\n");
			return (1);
		}
		send_message(pid, str);
		return (0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		ft_putstr("usage : ./client <PID> message");
	if (ft_atoi_mini(av[1], &pid) == 0)
	{
		ft_putstr("Invalid Arguments\n");
		return (1);
	}
	else
		return (send(pid, av[2]));
}