/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/02 17:03:12 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_2img(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if ((x > 0 && x <= 1920) && (y > 0 && y < 1080))
	{
	dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
	*(unsigned int *)dst = color;
	}
}

void	set_var( int *e, int *del, int *d, int *inc)
{
	d[0] = 2 * e[0];
	d[1] = 2 * e[1];
	del[0] = e[0];
	del[1] = e[1];
	inc[0] = 1;
	inc[1] = 1;
}

void	case_dx_dy(int *step, t_line line, t_vars *vars)
{
	int	i;
	int	del[2];
	int	d[2];
	int	inc[2];

	i = 0;
	set_var(step, del, d, inc);
	if (line.x1 > line.x2)
		inc[0] = -1;
	if (line.y1 > line.y2)
		inc[1] = -1;
	while (i <= del[0])
	{
		pixel_2img(vars, line.x1, line.y1, 0x00FF0000);
		i++;
		line.x1 += inc[0];
		step[0] -= d[1];
		if (step[0] < 0)
		{
			line.y1 += inc[1];
			step[0] += d[0];
		}
	}
}

void	case_dy_dx(int *step, t_line line, t_vars *vars)
{
	int	i;
	int	del[2];
	int	d[2];
	int	inc[2];

	i = 0;
	set_var(step, del, d, inc);
	if (line.x1 > line.x2)
		inc[0] = -1;
	if (line.y1 > line.y2)
		inc[1] = -1;
	while (i <= del[1])
	{
		pixel_2img(vars, line.x1, line.y1, 0x00FF0000);
		i++;
		line.y1 += inc[1];
		step[1] -= d[0];
		if (step[1] < 0)
		{
			line.x1 += inc[0];
			step[1] += d[1];
		}
	}
}

void	draw_segment(t_vars *vars, t_data *data, t_line line)
{
	(void)data;
	int		step[2];

	step[0] = abs((int) line.x2 - (int) line.x1);
	step[1] = abs((int) line.y2 - (int) line.y1);
	if (step[0] > step[1])
		case_dx_dy(step, line, vars);
	else if (step[1] > step[0])
		case_dy_dx(step, line, vars);
}

// void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
// {
// 	double	angle;

// 	*x = (*x - data->x / 2) * data->zoom;
// 	*y = (*y - data->y / 2) * data->zoom;
// 	angle = data->angle_x * (M_PI / 180.0);
// 	*y = *y * cos(angle) - z * sin(angle);
// 	z = *y * sin(angle) + z * cos(angle);
// 	angle = data->angle_y * (M_PI / 180.0);
// 	*x = *x * cos(angle) + z * sin(angle);
// 	angle = data->angle_z * (M_PI / 180.0);
// 	*x = *x * cos(angle) - *y * sin(angle);
// 	*y = *x * sin(angle) + *y * cos(angle);
// 	*x += data->shift_x;
// 	*y += data->shift_y;
// }

void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
{
	double	y_transf_iso;
	double	x_transf_iso;
	double	trsx;
	double	trsy;

	trsx = (1920 / 2) * (1);
	trsy = (1080 / 2) * (1);
	x_transf_iso = (*x - *y) * cos(0.523599);
	y_transf_iso = ((-1) * z + (*x + *y)) * sin(0.523599);
	*x = trsx + x_transf_iso * data->zoom;
	*y = trsy + y_transf_iso * data->zoom;
}

void	ft_horizon(t_data *data, t_vars *vars)
{
	int		x;
	int		y;
	t_line	line;
	(void)vars;
	y = 0;
	while (y <= data->y - 1)
	{
		x = 0;
		while (x < data->x - 1)
		{
			line.x1 = x;
			line.y1 = y;
			line.x2 = line.x1 + 1;
			line.y2 = line.y1;
			ft_zoom_rotate(data, &line.x1, &line.y1, data->value[y][x]);
			ft_zoom_rotate(data, &line.x2, &line.y2, data->value[y][x + 1]);
			draw_segment(vars, data, line);
			if (data->value[y][x] == 0)
				printf(" %d ", data->value[y][x]);
			else
				printf("%d ", data->value[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_vertical(t_data *data, t_vars *vars)
{
	int		x;
	int		y;
	t_line	line;

	x = 0;
	while (x < data->x - 1)
	{
		y = 0;
		while (y < data->y - 1)
		{
			line.x1 = x;
			line.y1 = y;
			line.x2 = line.x1;
			line.y2 = line.y1 + 1;
			ft_zoom_rotate(data, &line.x1, &line.y1, data->value[y][x]);
			ft_zoom_rotate(data, &line.x2, &line.y2, data->value[y + 1][x]);
			// printf("%f/%f\n", line.x1, line.y1);
			// printf("n2 %f/%f\n", line.x2, line.y2);
			draw_segment(vars, data, line);
			y++;
		}
		x++;
	}
}
