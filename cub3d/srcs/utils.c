/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 13:46:41 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 12:08:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	deallocate_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map != NULL)
	{
		while (i < map->size_y)
		{
			free(map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	ft_exit(char *str, int fd, int exit_status)
{
	ft_putendl_fd(str, fd);
	exit(exit_status);
}

void	check_path(char *path, char *file)
{
	int	i;

	i = ft_strlen(path) - 4;
	if (ft_strncmp(path + i, file, ft_strlen(file)) != 0)
	{
		ft_putstr_fd("Format error : ", 2);
		ft_putendl_fd(file, 2);
		exit(1);
	}
}

void	ra_to_pi(t_game *game, t_var *var)
{
	if (var->ra == 0 || var->ra == PI)
	{
		var->rx = game->map.player_pos_x;
		var->ry = game->map.player_pos_y;
		var->dof = game->map.size_y;
	}
}
