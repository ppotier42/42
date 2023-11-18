/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rayon.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:16:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/15 17:28:50 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*Initialise la position du joueur et lance des rayons pour le rendu 3D.*/

void	set_player_in(t_game *game)
{
	int	rayon;

	rayon = 0;
	game->map.pangle2 = game->map.pangle - (DEG / 4) * (NBR_RAYS / 2);
	while (rayon < NBR_RAYS)
	{
		if (game->map.pangle2 < 0)
			game->map.pangle2 += 2 * PI;
		else if (game->map.pangle2 > 2 * PI)
			game->map.pangle2 -= 2 * PI;
		game->r = rayon;
		if (check_horizontal(game, 0) < check_vertical(game, 0))
		{
			game->playerdist = check_horizontal(game, 0);
			check_horizontal(game, 1);
		}
		else
		{
			game->playerdist = check_vertical(game, 0);
			check_vertical(game, 1);
		}
		game->map.pangle2 += DEG / 4;
		rayon++;
	}
}

/*Trace un rayon sur la minimap dans une direction définie par l'angle `fov`
et dessine les rayons jusqu'à ce qu'un mur soit rencontré.*/

void	rayon(t_game *game, double fov, int i)
{
	double	x;
	double	y;

	x = (game->map.player_pos_x / CUBSIZE) * MINIMAP;
	y = (game->map.player_pos_y / CUBSIZE) * MINIMAP;
	while (i < 60)
	{
		if (game->map.map[(int)y / MINIMAP][(int)x / MINIMAP] == '1'
			|| game->map.map[(int)y / MINIMAP][(int)x / MINIMAP] == '2')
			break ;
		my_mlx_pixel_put(game->img, (int)x, (int)y, 0xFFFFFF);
		x += cos(fov);
		y += sin(fov);
	}
}

void	draw_rayon(t_game *game)
{
	double	starta;
	double	enda;
	int		i;

	i = -1;
	starta = game->map.pangle - PI / 6.0;
	enda = game->map.pangle + PI / 6.0;
	while (++i < 60)
		rayon(game, starta + (enda - starta) * i / (45 - 1), i);
}

int	draw_map(t_game *game)
{
	draw_ceiling(game);
	draw_floor(game);
	set_player_in(game);
	render_map(game);
	draw_mini_player(game);
	draw_rayon(game);
	mlx_put_image_to_window(game->img->mlx, game->img->win,
		game->img->img, 0, 0);
	return (0);
}
