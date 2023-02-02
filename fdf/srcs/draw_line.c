/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/30 16:34:20 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../mlxOS/mlx.h"
//#include "../libft/libft.h"
#include "fdf.h"

void	ft_bresenham(t_map *map, t_data *data)
{
	map->x = 0;
	map->y = 0;
	map->z=	map->data->value[(int)map->y][(int)map->x];
	map->x1 = x + 1;
	map->y1 = y;
	map->z1 = map->data->value[(int)map->y][(int)map->x];
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
			mlx_pixel_put(data->mlx, data->mlx_window, x1, y1, 0x696969);
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

void	iso_transfert(t_map *map, t_data *data)
{
	x = (x - y) * cos(0.523599);
	y = ((-1) * z + (x + y)) * sin(0.523599);
	x += 200;
	y += 200;
	x1 = (x1 - y1) * cos(0.523599);
	y1 = ((-1) * z1 + (x1 + y1)) * sin(0.523599);
	x1 += 200;
	y1 += 200;
}
void	ft_draw_line(t_data *data)
{
	t_map	*map;
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_iso(map, data);
			if (y < data->height - 1)
				ft_bresenham(map, data);
			x++;
		}
		y++;
	}
}