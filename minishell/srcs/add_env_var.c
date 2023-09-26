/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:56:24 by robin             #+#    #+#             */
/*   Updated: 2023/09/26 14:17:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	list_len(char **list)
{
	int		i;

	i = 0;
	while (list[i] != NULL)
		i++;
	return (i);
}

int	add_env_var(char *var, t_env *envcpy)
{
	char	**new_env_copy;
	int		i;

	new_env_copy
		= (char **)malloc(sizeof(char *) * (list_len(envcpy->env) + 2));
	if (new_env_copy == NULL)
		return (ERROR);
	i = 0;
	while (envcpy->env[i])
	{
		new_env_copy[i] = envcpy->env[i];
		i++;
	}
	new_env_copy[i] = var;
	new_env_copy[i + 1] = NULL;
	free(envcpy->env);
	envcpy->env = new_env_copy;
	return (SUCCESS);
}
