/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 16:04:04 by robin             #+#    #+#             */
/*   Updated: 2023/09/28 11:53:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_var_name(char *var)
{
	if (var[0] == '_' || var[1] == '=')
		return (3);
	if (!ft_isalpha(var[0]))
	{
		ft_putendl_fd("minishell: export: not a valid identifier", 2);
		return (ERROR);
	}
	return (SUCCESS);
}

int	export_one_arg(char *var, t_env *envcpy)
{
	char	*new_var;
	int		var_index;
	int		status;

	status = check_var_name(var);
	if (status == ERROR)
		return (ERROR);
	if (status == 3)
		return (SUCCESS);
	new_var = ft_strdup(var);
	if (new_var == NULL)
		return (ERROR);
	var_index = get_env_var_index(new_var, envcpy->env);
	if (var_index == -1 && add_env_var(new_var, envcpy) == ERROR)
	{
		free(new_var);
		return (ERROR);
	}
	else if (var_index != -1)
	{
		free(envcpy->env[var_index]);
		envcpy->env[var_index] = new_var;
	}
	return (SUCCESS);
}

void	sort_env(t_env *envcpy)
{
	char	**dup;
	char	*tmp;
	size_t	i;
	size_t	j;

	dup = envcpy->env;
	i = 0;
	while (dup[i])
	{
		j = i + 1;
		while (dup[j])
		{
			if (ft_strcmp(dup[i], dup[j]) > 0)
			{
				tmp = dup[i];
				dup[i] = dup[j];
				dup[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	print_all_env(char **env)
{
	int		i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("declare -x %s\n", env[i]);
		i++;
	}
	return (SUCCESS);
}

int	ft_export(char **split_line, t_env *envcpy)
{
	int	last_status;
	int	i;

	i = 1;
	if (split_line[1] == NULL)
	{
		sort_env(envcpy);
		return (print_all_env(envcpy->env));
	}
	else
	{
		while (split_line[i] != NULL)
		{
			last_status = export_one_arg(split_line[i], envcpy);
			i++;
		}
	}
	return (last_status);
}
