/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:54:39 by robin             #+#    #+#             */
/*   Updated: 2023/11/13 15:23:46 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

void	move_cam(t_game *game, int keycode)
{
	if (keycode == 123)
	{
		game->map.pangle -= 0.1;
		game->map.playerdir.x = cos(game->map.pangle) * 5;
		game->map.playerdir.y = sin(game->map.pangle) * 5;
	}
	else if (keycode == 124)
	{
		game->map.pangle += 0.1;
		game->map.playerdir.x = cos(game->map.pangle) * 5;
		game->map.playerdir.y = sin(game->map.pangle) * 5;
	}
}

void	moove_lr(t_game *game, int keycode)
{
	double	nextx;
	double	nexty;

	check_wall(game);
	if (keycode == 2)
	{
		nextx = game->map.player_pos_x - game->map.playerdir.y * MOVESPEED;
		nexty = game->map.player_pos_y + game->map.playerdir.x * MOVESPEED;
		if (game->map.map[(int)nexty / CUBSIZE][(int)nextx / CUBSIZE] == '0')
		{
			game->map.player_pos_x = nextx;
			game->map.player_pos_y = nexty;
		}
	}
	if (keycode == 0)
	{
		nextx = game->map.player_pos_x + game->map.playerdir.y * MOVESPEED;
		nexty = game->map.player_pos_y - game->map.playerdir.x * MOVESPEED;
		if (game->map.map[(int)nexty / CUBSIZE][(int)nextx / CUBSIZE] == '0')
		{
			game->map.player_pos_x = nextx;
			game->map.player_pos_y = nexty;
		}
	}
}

void	move_updown(t_game *game, int keycode)
{
	double	nextx;
	double	nexty;

	check_wall(game);
	if (keycode == 13)
	{
		nextx = game->map.player_pos_x + game->map.playerdir.x * MOVESPEED;
		nexty = game->map.player_pos_y + game->map.playerdir.y * MOVESPEED;
		if (game->map.map[(int)nexty / CUBSIZE][(int)nextx / CUBSIZE] == '0')
		{
			game->map.player_pos_x = nextx;
			game->map.player_pos_y = nexty;
		}
	}
	if (keycode == 1)
	{
		nextx = game->map.player_pos_x - game->map.playerdir.x * MOVESPEED;
		nexty = game->map.player_pos_y - game->map.playerdir.y * MOVESPEED;
		if (game->map.map[(int)nexty / CUBSIZE][(int)nextx / CUBSIZE] == '0')
		{
			game->map.player_pos_x = nextx;
			game->map.player_pos_y = nexty;
		}
	}
}

int	close_win(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->img->mlx, game->img->win);
	exit (0);
	return (0);
}

int	moove_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		close_win(keycode, game);
	if (keycode == 0 || keycode == 2)
		moove_lr(game, keycode);
	if (keycode == 1 || keycode == 13)
		move_updown(game, keycode);
	if (keycode == 123 || keycode == 124)
		move_cam(game, keycode);
	draw_mini_player(game);
	draw_map(game);
	return (0);
}
