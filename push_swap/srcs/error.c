/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:42:23 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/24 13:05:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_msg_error(char *str)
{
	ft_putendl_fd(str, 2);
	exit(0);
}

int	ft_check_double(int num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (0);
		i++;
	}
	return (1);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_error(int ac, char **argv)
{
	int		i;
	int		tmp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		// printf(" %d", tmp);
		if (!ft_isnum(args[i]))
			ft_msg_error("Error");
		if (!ft_check_double(tmp, args, i))
			ft_msg_error("Error");
		if (tmp < INT32_MIN || tmp > INT32_MAX)
			ft_msg_error("Error");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
