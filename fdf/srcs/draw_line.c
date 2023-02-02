/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/30 16:34:20 by ppotier          ###   ########.fr       */
=======
/*   Updated: 2023/01/31 23:17:37 by ppotier          ###   ########.fr       */
>>>>>>> 216be640082a204535bac26a662dcb76a7658ebf
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

<<<<<<< HEAD
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
=======
// static void	ft_bresenham(t_line line, t_data *data, t_vars vars);
static void	ft_zoom_rotate(t_data *data, double *x, double *y, double z);
static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

void	draw(t_data *data, t_vars vars)
{
	t_line	line;
	printf("draw\n");
	line.y1 = -1;
	while (++line.y1 < data->y)
>>>>>>> 216be640082a204535bac26a662dcb76a7658ebf
	{
		line.x1 = -1;
		while (++line.x1 < data->x)
		{
			if (line.x1 < data->y - 1)
			{
				line.x2 = line.x1 + 1;
				line.y2 = line.y1;
				ft_bresenham(data, vars);
			}
			if (line.y1 < data->x - 1)
			{
				line.x2 = line.x1;
				line.y2 = line.y1 + 1;
				ft_bresenham(data, vars);
			}
		}
	}
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.img, 0, 0);
}

void	ft_bresenham(t_data *data, t_vars vars)
{
	t_line	line;
	double	x_step;
	double	y_step;
	double	z1;
	double	z2;

	z1 = data->value[(int)line.y1][(int)line.x1] * data-> lift;
	z2 = data->value[(int)line.y2][(int)line.x2] * data-> lift;
	if (z1 || z2)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	ft_zoom_rotate(data, &line.x1, &line.y1, z1);
	ft_zoom_rotate(data, &line.x2, &line.y2, z2);
	x_step = line.x2 - line.x1;
	y_step = line.y2 - line.y1;
	line.max = fmax(fabs(x_step), fabs(y_step));
	x_step /= line.max;
	y_step /= line.max;
	while ((int)(line.x1 - line.x2) || (int)(line.y1 - line.y2))
	{
		printf("%lf %lf", line.x1, line.y1);
		my_mlx_pixel_put(&vars, (int)line.x1, (int)line.y1, 0xFF0000);
		line.x1 += x_step;
		line.y1 += y_step;
	}
}

static void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
{
	double	angle;
	printf("zoom\n");
	*x = (*x - data->x / 2) * data->zoom;
	*y = (*y - data->y / 2) * data->zoom;
	angle = data->angle_x * (M_PI / 180.0);
	*y = *y * cos(angle) - z * sin(angle);
	z = *y * sin(angle) + z * cos(angle);
	angle = data->angle_y * (M_PI / 180.0);
	*x = *x * cos(angle) + z * sin(angle);
	angle = data->angle_z * (M_PI / 180.0);
	*x = *x * cos(angle) - *y * sin(angle);
	*y = *x * sin(angle) + *y * cos(angle);
	*x += data->shift_x;
	*y += data->shift_y;
}

<<<<<<< HEAD
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
=======

static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 1920 && y < 1080 && x > 0 && y > 0)
	{
		dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
		*(unsigned int *) dst = color;
>>>>>>> 216be640082a204535bac26a662dcb76a7658ebf
	}
}