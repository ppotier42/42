/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:28:22 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/26 18:18:02 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlxOS/mlx.h"
#include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	line(void *mlx, void *win, int begx, int begy, int endx, int endy, int clr)
{
	double	deltax;
	double	deltay;
	int		pixels;
	double	pixelx;
	double	pixely;

	deltax = endx - begx;
	deltay = endy - begy;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	deltax /= pixels;
	deltay /= pixels;
	pixelx = begx;
	pixely = begy;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelx, pixely, clr);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "so_long");
	line(mlx, mlx_win, 400, 400, 0, 0, 0x0000FF);
	line(mlx, mlx_win, 400, 0, 0, 400, 0x0000FF);
	line(mlx, mlx_win, 0, 200, 400, 200, 0x0000FF);
	mlx_loop(mlx);
	return (0);
}