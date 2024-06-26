/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:29:39 by ppotier           #+#    #+#             */
/*   Updated: 2023/09/26 15:49:38 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **split_line, t_env *envcpy)
{
	int	i;
	int	flag;

	(void)envcpy;
	i = 1;
	flag = 0;
	if (split_line[1] == NULL)
		return (printf("\n"), 1);
	while (split_line[1][0] == '-' && split_line[1][i] == 'n')
	{
		flag = 1;
		i++;
	}
	if (flag == 1)
		i = 2;
	while (split_line[i])
	{
		printf("%s", split_line[i]);
		i++;
		if (split_line[i] != NULL)
			printf(" ");
	}
	if (flag == 0)
		printf("\n");
	return (0);
}
