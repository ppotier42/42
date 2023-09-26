/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:46:46 by robin             #+#    #+#             */
/*   Updated: 2023/09/26 15:55:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	export_pwd(const char *to_join, t_env *envcpy)
{
	char	*joined_export_split_line;
	char	**splited_export_split_line;
	int		exit_code;

	joined_export_split_line
		= ft_strjoin(to_join, envcpy->current_working_directory);
	if (joined_export_split_line == NULL)
		return (ERROR);
	splited_export_split_line = ft_split(joined_export_split_line, ' ');
	if (splited_export_split_line == NULL)
	{
		free(joined_export_split_line);
		return (ERROR);
	}
	exit_code = ft_export(splited_export_split_line, envcpy);
	free(joined_export_split_line);
	split_free(splited_export_split_line);
	return (exit_code);
}

static int	change_directory_in_env(t_env *envcpy)
{
	if ((get_env_var_index("OLDPWD=", envcpy->env) != -1)
		&& (export_pwd((char *)"export OLDPWD=", envcpy)))
		return (ERROR);
	getcwd(envcpy->current_working_directory, MAX_PATH_LEN + 1);
	if ((get_env_var_index((char *)"PWD=", envcpy->env) != -1)
		&& (export_pwd((char *)"export PWD=", envcpy)))
		return (ERROR);
	return (SUCCESS);
}

static int	change_dir(char *new_path, t_env *envcpy)
{
	if (chdir(new_path) != 0)
	{
		perror("chdir");
		return (errno);
	}
	if (change_directory_in_env(envcpy) == 1)
	{
		perror("chdirinenv");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	go_home(t_env *envcpy)
{
	char	*home;

	home = get_env_var_value((char *)"HOME", envcpy);
	if (home == NULL)
		return (ERROR);
	change_dir(home, envcpy);
	free(home);
	return (SUCCESS);
}

int	ft_cd(char **split_line, t_env *envcpy)
{
	int		argc;
	char	*old_pwd;

	getcwd(envcpy->current_working_directory, MAX_PATH_LEN);
	argc = 0;
	while (split_line[argc] != NULL)
		argc++;
	if (argc == 1)
		return (go_home(envcpy));
	if (ft_strncmp(split_line[1], "-", 2) == 0)
	{
		if (argc > 2)
			return (ERROR);
		old_pwd = get_env_var_value("OLDPWD", envcpy);
		if (old_pwd == NULL)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
			return (ERROR);
		}
		change_dir(old_pwd, envcpy);
		free(old_pwd);
		return (SUCCESS);
	}
	return (change_dir(split_line[1], envcpy));
}
