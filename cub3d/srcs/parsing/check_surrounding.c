/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surrounding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:59:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/16 12:02:45 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	check_outside(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->map[y][x] == '0')
			{
				if (x == 0 || x == map->size_x - 1
					|| y == 0 || y == map->size_y - 1)
					return (1);
				if (map->map[y][x - 1] == '2'
						|| map->map[y - 1][x] == '2'
						|| map->map[y][x + 1] == '2'
						|| map->map[y + 1][x] == '2')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_surrounding(t_map *map)
{
	if (check_outside(map) == 1)
		ft_exit("Map is not closed", 2, 1);
	return (0);
}
