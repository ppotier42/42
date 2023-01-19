/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/19 02:07:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlxOS/mlx.h"
#include "../libft/libft.h"
#include "fdf.h"

void	ft_bresenham(float x, float y, float x1, float y1, t_data *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	
	z = data->value[(int)y][(int)x];

//zoom
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
//3D
	x = (x - y) * cos(0.523599);
	y = ((-1) * z + (x + y)) * sin(0.523599);
	x += 150;
	y += 150;
	x1 = (x1 - y1) * cos(0.523599);
	y1 = ((-1) * z + (x1 + y1)) * sin(0.523599);
	x1 += 150;
	y1 += 150;
	x_step = x1 - x;
	y_step = y1 - y;
	max = fmaxf(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx, data->mlx_window, x, y, 0xc0f4f0);
		x += x_step;
		y += y_step;
	}
}

void	ft_draw_line(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				ft_bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}