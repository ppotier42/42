/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:55 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/13 13:29:32 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
{
	double	y_transf_iso;
	double	x_transf_iso;
	double	trsx;
	double	trsy;

	trsx = (1000 / 2) * (1);
	trsy = (600 / 2) * (1);
	x_transf_iso = (*x - *y) * cos(0.523599);
	y_transf_iso = ((-1) * z + (*x + *y)) * sin(0.523599);
	*x = trsx + x_transf_iso * data->zoom;
	*y = trsy + y_transf_iso * data->zoom;
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

void	ft_set_map(t_data *data)
{
	data->shift_x = data->size_x / 2;
	data->shift_y = data->size_y / 2;
	data->angle_x = 45;
	data->angle_y = 45;
	data->angle_z = 1;
	data->zoom = set_zoom(data);
	data->lift = 1;
}

void	set_window_size(t_data *data)
{
	if (data->y >= 0 && data->y < 99)
		data->size_y = 400;
	else if (data->y >= 100 && data->y < 500)
		data->size_y = 800;
	else
		data->size_y = 1200;
	if (data->x >= 0 && data->x < 99)
		data->size_x = 400;
	else if (data->x >= 100 && data->x < 500)
		data->size_x = 800;
	else
		data->size_x = 1200;
}

float	set_zoom(t_data *data)
{
	float	zoom1;
	float	zoom2;

	if (data->x >= 0 && data->x < 99)
		zoom1 = 10.0;
	else if (data->x >= 100 && data->x < 500)
		zoom1 = 5.0;
	else
		zoom1 = 1.0;
	if (data->y >= 0 && data->y < 99)
		zoom2 = 10.0;
	else if (data->y >= 100 && data->y < 500)
		zoom2 = 5.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}
