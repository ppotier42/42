/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:29:11 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/26 14:31:00 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ms_getenv_cont(char *name, t_env *envcpy)
{
	int		i;
	char	*match;

	i = 0;
	while (envcpy->env[i] != 0)
	{
		match = ft_strnstr(envcpy->env[i], name, ft_strlen(envcpy->env[i]));
		if (match)
		{
			if (match == envcpy->env[i] && match[ft_strlen(name)] == '=')
				return (ft_strdup(envcpy->env[i] + (ft_strlen(name)) + 1));
		}
		i++;
	}
	return (NULL);
}

char	*ms_getenv(char	*name, t_env *envcpy)
{
	int		i;
	char	*match;

	i = 0;
	while (envcpy->env[i] != 0)
	{
		match = ft_strnstr(envcpy->env[i], name, ft_strlen(envcpy->env[i]));
		if (match)
		{
			if (match == envcpy->env[i] && match[ft_strlen(name)] == '=')
				return (ft_strdup(envcpy->env[i]));
		}
		i++;
	}
	return (NULL);
}
