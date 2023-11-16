/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:17:36 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/16 12:00:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	render(t_game *game, int x, int y, char wall)
{
	int	x2;
	int	y2;

	x2 = x + MINIMAP;
	y2 = y + MINIMAP;
	while (++x < x2)
	{
		while (++y < y2)
		{
			if (y == y2 - 1 || x == x2 -1)
				my_mlx_pixel_put(game->img, x, y, 0x696969);
			else if (wall == '1')
				my_mlx_pixel_put(game->img, x, y, 0xFFFFFF);
			else if (wall == '0')
				my_mlx_pixel_put(game->img, x, y, 0x000000);
		}
		y = y2 - MINIMAP;
	}
}

void	render_square(t_game *game, int x, int y, char wall)
{
	if (wall == '1')
		render(game, x, y, '1');
	else if (wall == '0')
		render(game, x, y, '0');
	else if (wall == '3')
		render(game, x, y, '2');
}

void	render_map(t_game *game)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (i < game->map.size_y)
	{
		x = 0;
		j = 0;
		while (j <= game->map.size_x)
		{
			if (j == game->map.size_x)
				break ;
			render_square(game, x, y, game->map.map[i][j]);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}

void	draw_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(game->img, x, y, game->map.ceiling_color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(game->img, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}
