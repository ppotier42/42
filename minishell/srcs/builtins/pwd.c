/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 19:26:53 by robin             #+#    #+#             */
/*   Updated: 2023/09/26 21:36:29 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_pwd(char **line, t_env *envcpy)
{
	int	index;

	(void)line;
	index = get_env_var_index("PWD=", envcpy->env);
	if (index != -1)
		printf("%s\n", envcpy->env[index] + 4);
	return (SUCCESS);
}
