/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:14:00 by ppotier           #+#    #+#             */
/*   Updated: 2023/10/20 13:00:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	allocate_map_int(t_game *game)
{
	game->map.map_int = (int *)malloc(sizeof(int)
			* (game->map.size_x * game->map.size_y));
	if (!game->map.map_int)
		ft_exit("Malloc error", 2, 1);
}

void	map_to_int(t_game *game)
{
	int	x;
	int	y;
	int	iter;

	y = 0;
	iter = 0;
	allocate_map_int(game);
	while (y < game->map.size_y)
	{
		x = 0;
		while (x < game->map.size_x)
		{
			if (game->map.map[y][x] == '0')
				game->map.map_int[iter] = 0;
			if (game->map.map[y][x] == '1')
				game->map.map_int[iter] = 1;
			iter++;
			x++;
		}
		y++;
	}
}
