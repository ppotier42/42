/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:44:31 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/15 15:22:01 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int n);
void	ft_putchar(char c);


void	rec(int n, int pid)
{
	int				shift;
	static int			i;
	static char		c;
	static pid_t	g_clientpid;

	g_clientpid = -1;
	i = 7;
	if (i == -1 || pid != g_clientpid)
	{
		i = 7;
		c = 0;
	g_clientpid = pid;
	}
	shift = 1 << (i);
	if (n != 0)
		c = (c | shift);
	// printf("%c\n", c);
	i--;
	if (i == -1)
		ft_putchar(c);
}

void	server(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
}

void	sig_handler(int sig, siginfo_t *info, void *ptr)
{
	(void)ptr;
	if (sig == SIGUSR1)
		rec(1, info->si_pid);
	if (sig == SIGUSR2)
		rec(0, info->si_pid);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = 0;
	act.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	server();
	while (1)
		pause();
	return (0);
}