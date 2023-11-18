/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:34:30 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 13:39:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	only_one_spawn(char **lines)
{
	int	i;
	int	j;
	int	spawn;

	i = 0;
	spawn = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (is_in_charset(lines[i][j], "NSWE"))
				spawn++;
			j++;
		}
		i++;
	}
	if (spawn > 1 || spawn <= 0)
		return (1);
	return (0);
}

static int	has_invalid_char(char **lines)
{
	int	i;
	int	j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j] != '\0')
		{
			if (!is_in_charset(lines[i][j], " 01NSWE"))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char **lines)
{
	if (has_invalid_char(lines) == 1)
		ft_exit("Invalid char in map", 2, 1);
	if (only_one_spawn(lines) == 1)
		ft_exit("Multiple spawn points", 2, 1);
	return (1);
}
