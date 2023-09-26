/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:45:54 by robin             #+#    #+#             */
/*   Updated: 2023/09/26 14:33:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	g_env;

static int	check_args(char **split_line)
{
	if (split_line[1] != NULL)
	{
		write(2, "minishell: env: too many arguments\n", 34);
		return (ERROR);
	}
	return (SUCCESS);
}

int	ft_env(char **split_line, t_env *envcpy)
{
	int		i;

	if (check_args(split_line) == ERROR)
		return (ERROR);
	i = 0;
	while (envcpy->env[i] != NULL)
	{
		printf("%s\n", envcpy->env[i]);
		i++;
	}
	return (SUCCESS);
}
