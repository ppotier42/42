/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:39:27 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/09 16:27:20 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit (0);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_win(keycode, vars);
	return (0);
}