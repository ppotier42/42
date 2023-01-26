/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/24 15:09:38 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham(float x1, float y1, float x2, float y2, t_data *data)
{
	float	ex;
	float	ey;
	int		x_neg = 1;
	int		y_neg = 1;
	int		dx;
	int		dy;
	int		i;
	int		Dx;
	int		Dy;
//zoom
	x1 *= data->zoom;
	y1 *= data->zoom;
/*3D
	x = (x - y) * cos(0.523599);
	y = ((-1) * z + (x + y)) * sin(0.523599);
	x += 200;
	y += 200;
	x1 = (x1 - y1) * cos(0.523599);
	y1 = ((-1) * z1 + (x1 + y1)) * sin(0.523599);
	x1 += 200;
	y1 += 200;*/
	if (x1 > x2)
		x_neg = -1;
	if (y1 > y2)
		y_neg = -1;
	ex = fabsf(x2 - x1);
	ey = fabsf(y2 - y1);
	dx = 2 * ex;
	dy = 2 * ey;
	Dx = ex;
	Dy = ey;
	i = 0;
	//printf("%f %f\n", ex, ey);
	if (Dx >= Dy)
	{
		while (i <= Dx)
		{
			i++;
			printf("Dx > Dy\n%f %f\n", x1, y1);
			mlx_pixel_put(data->mlx, data->mlx_window, x1, y1, 0xffffff);
			x1 += x_neg;
			ex -= dy;
			if (ex < 0)
			{
				y1 += y_neg;
				ex += dx;
			}
		}
	}
	if (Dx < Dy)
	{
		while (i <= Dy)
		{
			printf("Dx < Dy\n%f %f\n", x2, y2);
			i++;
			mlx_pixel_put(data->mlx, data->mlx_window, x1, y1, 0x850606);
			y1 += y_neg;
			ey -= dx;
			if (ey < 0)
			{
				x1 += x_neg;
				ey += dy;
			}
		}
	}
}


void	ft_draw_line(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)//hauteur [y][0]
	{
		x = 0;
		while (x < data->width)//largeur[y][x]
		{
			if (x < data->width - 1)
				ft_bresenham((float)data->height, (float)data->width, x, y, data);
			if (y < data->height - 1)
				ft_bresenham(x, y, (float)data->height, (float)data->width, data);
			x++;
		}
		y++;
	}
}