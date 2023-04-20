/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:30:40 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/21 00:03:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	check_doubles(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && nb_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	args_is_digit(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0' && !ft_isdigit(str[i]))
		return (0);
	return (1);
}

int	args_is_zero(char *str)
{
	int	i;

	i = 0;
	if (ft_is_sign(str[i]))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	ft_check_input(int ac, char **av)
{
	int		i;
	int		nb_zeros;
	char	**args;

	nb_zeros = 0;
	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		args = av;
		i = 1;
	}
	if (!args)
		return (0);
	while (args[++i])
	{
		if (!ft_check_int(args[i]) || (!args_is_digit(args[i])))
		{
			ft_free(args);
			return (0);
		}
		nb_zeros += args_is_zero(args[i]);
	}
	if (nb_zeros > 1 || check_doubles(args))
	{
		ft_free(args);
		return (0);
	}
	ft_free(args);
	return (1);
}
