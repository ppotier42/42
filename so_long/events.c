/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 21:53:09 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/16 22:06:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxOS/mlx.h"

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "test");
	mlx_hook(vars.win, 2, 5, close, &vars);
	mlx_loop(vars.mlx);
}
