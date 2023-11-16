/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:32:39 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/11 15:29:27 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	draw_mini_player(t_game *game)
{
	double	sx;
	double	sy;
	double	x;
	double	y;

	sx = (game->map.player_pos_x / CUBSIZE) * MINIMAP;
	sy = (game->map.player_pos_y / CUBSIZE) * MINIMAP;
	x = sx - 2.0;
	while (x < sx + 2.0)
	{
		y = sy - 2.0;
		while (y < sy + 2.0)
		{
			my_mlx_pixel_put(game->img, (int)x, (int)y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}
