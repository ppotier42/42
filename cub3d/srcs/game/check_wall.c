/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:00:13 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/15 17:39:25 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	select_textures(t_game *game, double rx, double ry, int y)
{
	if (game->flag == 1)
	{
		if (game->map.player_pos_x < rx)
			print_wall(game, ry, y, WEST);
		else
			print_wall(game, ry, y, EAST);
	}
	else
	{
		if (game->map.player_pos_y < ry)
			print_wall(game, rx, y, SOUTH);
		else
			print_wall(game, rx, y, NORTH);
	}
}

void	draw_line3d(t_game *game, double rx, double ry)
{
	int	y;
	int	x2;

	game->ax = game->r * 2;
	x2 = game->ax + 2;
	while (game->ax < x2)
	{
		y = 0;
		while (y < game->lineh)
		{
			select_textures(game, rx, ry, y);
			y++;
		}
		game->ax++;
	}
}

float	dist_wall(t_game *game, double rx, double ry)
{
	float	len;
	double	startx;
	double	starty;

	startx = game->map.player_pos_x;
	starty = game->map.player_pos_y;
	len = sqrt(pow(rx - startx, 2) + pow(ry - starty, 2));
	return (len);
}

/* trace un rayon et détermine l'intersection
de ce rayon avec les murs. La recherche d'intersection est effectuée
en déplaçant le point d'intersection le long du rayon, en vérifiant si ce point
se trouve dans une case de mur. Les résultats de cette fonction 
sont utilisés pour calculer la hauteur et la position verticale de la ligne
projetée sur l'écran. */

void	get_intersection(t_game *game, t_var *var)
{
	int	mx;
	int	my;
	int	mpos;

	while (var->dof < game->map.size_x)
	{
		mx = (int)var->rx >> 6;
		my = (int)var->ry >> 6;
		mpos = my * game->map.size_x + mx;
		if (mpos > 0 && mpos < game->map.size_x * game->map.size_y
			&& (game->map.map_int[mpos] == 1 || game->map.map_int[mpos] == 2))
			var->dof = game->map.size_x;
		else
		{
			var->rx += var->xo;
			var->ry += var->yo;
			var->dof += 1;
		}
		game->lineh = (CUBSIZE * HEIGHT) / game->playerdist;
		if (game->lineh > HEIGHT)
			game->lineh = HEIGHT;
		game->lineo = HEIGHT / 2 - game->lineh / 2;
	}
}

int	ft_calcul(t_game *game, t_var *var, int flag, int flag2)
{
	ra_to_pi(game, var);
	game->fish = game->map.pangle - var->ra;
	if (game->fish < 0)
		game->fish += 2 * PI;
	if (game->fish > 2 * PI)
		game->fish -= 2 * PI;
	game->playerdist = game->playerdist + cos(game->fish);
	get_intersection(game, var);
	if (flag == 0)
		return (dist_wall(game, var->rx, var->ry));
	else
	{
		game->flag = flag2;
		draw_line3d(game, var->rx, var->ry);
	}
	return (0);
}
