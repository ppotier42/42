/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 13:58:09 by robin             #+#    #+#             */
/*   Updated: 2023/09/26 15:00:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	remove_env_var(int index_var, char **env)
{
	int		last;

	last = 0;
	while (env[last] != NULL)
		last++;
	free(env[index_var]);
	env[index_var] = env[last - 1];
	env[last - 1] = NULL;
	return (SUCCESS);
}

static int	unset_one_variable(char *line, char **env)
{
	int		var_index;
	int		i;
	int		flag;

	flag = 0;
	if (ft_isdigit(line[0]) != 0)
		return (SUCCESS);
	i = -1;
	while (line[++i] && (ft_isdigit(line[i])
			|| ft_isalpha(line[i]) || line[i] == '_'))
		if (line[i] == '=')
			flag = 1;
	if (line[i] != '\0')
		return (SUCCESS);
	line[i] = '\0';
	if (flag == 1)
		var_index = get_env_var_index(line, env);
	else
		var_index = get_env_var_index_nonequal(line, env);
	if (var_index == -1)
		return (SUCCESS);
	remove_env_var(var_index, env);
	return (SUCCESS);
}

int	ft_unset(char **split_line, t_env *envcpy)
{
	int	last_status;
	int	i;

	if (split_line[1] == NULL)
		return (SUCCESS);
	i = 0;
	while (++i && split_line[i])
		last_status = unset_one_variable(split_line[i], envcpy->env);
	return (last_status);
}
