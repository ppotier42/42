/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:05:22 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/15 17:44:11 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

/*Vérifie les intersections horizontales/verticales du rayon avec les murs.
Les résultats sont utilisés pour déterminer la distance au mur
 le plus proche dans chaque direction.*/

float	check_horizontal(t_game *game, int flag)
{
	t_var	var;

	var.ra = game->map.pangle2;
	var.atan = -1 / tan(var.ra);
	var.dof = 0;
	if (var.ra > PI)
	{
		var.ry = (((int)game->map.player_pos_y >> 6) << 6) - 0.0001;
		var.rx = (game->map.player_pos_y - var.ry) \
			* var.atan + game->map.player_pos_x;
		var.yo = -CUBSIZE;
		var.xo = -var.yo * var.atan;
	}
	else
	{
		var.ry = (((int)game->map.player_pos_y >> 6) << 6) + CUBSIZE;
		var.rx = (game->map.player_pos_y - var.ry) \
			* var.atan + game->map.player_pos_x;
		var.yo = CUBSIZE;
		var.xo = -var.yo * var.atan;
	}
	return (ft_calcul(game, &var, flag, 0));
}

float	check_vertical(t_game *game, int flag)
{
	t_var	var;

	var.ra = game->map.pangle2;
	var.atan = -tan(var.ra);
	var.dof = 0;
	if (var.ra > PI2 && var.ra < PI3)
	{
		var.rx = (((int)game->map.player_pos_x >> 6) << 6) - 0.0001;
		var.ry = (game->map.player_pos_x - var.rx) \
			* var.atan + game->map.player_pos_y;
		var.xo = -CUBSIZE;
		var.yo = -var.xo * var.atan;
	}
	else
	{
		var.rx = (((int)game->map.player_pos_x >> 6) << 6) + CUBSIZE;
		var.ry = (game->map.player_pos_x - var.rx) \
			* var.atan + game->map.player_pos_y;
		var.xo = CUBSIZE;
		var.yo = -var.xo * var.atan;
	}
	return (ft_calcul(game, &var, flag, 1));
}

/* Vérifie la distance jusqu'aux murs dans les quatre directions cardinales.
  Met à jour les distances dans la structure .*/
void	check_wall(t_game *game)
{
	int	r;
	int	distance;

	r = 0;
	game->map.pangle2 = game->map.pangle - (DEG * 180);
	while (r < 4)
	{
		if (check_horizontal(game, 0) < check_vertical(game, 0))
			distance = check_horizontal(game, 0);
		else
			distance = check_vertical(game, 0);
		if (r == 0)
			game->dwall_s = distance;
		if (r == 1)
			game->dwall_w = distance;
		if (r == 2)
			game->dwall_n = distance;
		if (r == 3)
			game->dwall_e = distance;
		game->map.pangle2 += DEG * 90;
		r++;
	}
}

int	get_color_from_textures(t_game *game, int x, int y, int wall)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char			*str;
	int				size;

	str = game->xpm_img[wall].addr;
	size = game->xpm_img[wall].win_w;
	b = str[(x * 4) + (size * y * 4)];
	g = str[(x * 4) + (size * y * 4) + 1];
	r = str[(x * 4) + (size * y * 4) + 2];
	return (((int)r << 16) + ((int)g << 8) + (int)b);
}

/* Prend une position verticale y sur l'écran,utilise 
une texture spécifiée par wall,et imprime une colonne 
de mur à l'écran en fonction de la position sur la 
texture (imgx) et du décalage vertical (offset). */

void	print_wall(t_game *game, double truc, int y, int wall)
{
	float	imgx;
	float	offset;
	int		color;

	imgx = (float)((int)truc % CUBSIZE);
	imgx = imgx / (float)CUBSIZE * (float)game->xpm_img[wall].win_w;
	offset = (float)game->xpm_img[wall].win_h / (float)game->lineh;
	offset *= (float)y;
	color = get_color_from_textures(game, (int)imgx, (int)offset, wall);
	my_mlx_pixel_put(game->img, game->ax, y + game->lineo, color);
}
