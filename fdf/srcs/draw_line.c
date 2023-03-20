/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:17:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/20 15:44:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		pixel_2img(vars, line.x1, line.y1, 0x696969);
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
		pixel_2img(vars, line.x1, line.y1, 0xF00020);
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
	int	step[2];

	(void)data;
	step[0] = abs((int) line.x2 - (int) line.x1);
	step[1] = abs((int) line.y2 - (int) line.y1);
	if (step[0] > step[1])
		case_dx_dy(step, line, vars);
	else if (step[1] > step[0])
		case_dy_dx(step, line, vars);
}

void	ft_horizon(t_data *data, t_vars *vars)
{
	int		x;
	int		y;
	t_line	line;

	y = 0;
	while (y <= data->height - 1)
	{
		x = 0;
		while (x < data->width - 1)
		{
			line.x1 = x;
			line.y1 = y;
			line.x2 = line.x1 + 1;
			line.y2 = line.y1;
			ft_zoom_rotate(data, &line.x1, &line.y1, data->value[y][x]);
			ft_zoom_rotate(data, &line.x2, &line.y2, data->value[y][x + 1]);
			draw_segment(vars, data, line);
			x++;
		}
		y++;
	}
}

void	ft_vertical(t_data *data, t_vars *vars)
{
	int		x;
	int		y;
	t_line	line;

	x = 0;
	while (x <= data->width - 1)
	{
		y = 0;
		while (y < data->height - 1)
		{
			line.x1 = x;
			line.y1 = y;
			line.x2 = line.x1;
			line.y2 = line.y1 + 1;
			ft_zoom_rotate(data, &line.x1, &line.y1, data->value[y][x]);
			ft_zoom_rotate(data, &line.x2, &line.y2, data->value[y + 1][x]);
			draw_segment(vars, data, line);
			y++;
		}
		x++;
	}
}
