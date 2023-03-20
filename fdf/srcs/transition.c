/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:55 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/20 15:57:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
{
	double	y_transf_iso;
	double	x_transf_iso;

	x_transf_iso = (*x - *y) * cos(0.523599);
	y_transf_iso = ((-1) * z + (*x + *y)) * sin(0.523599);
	*x = data->shift_x + x_transf_iso * data->zoom;
	*y = data->shift_y + y_transf_iso * data->zoom;
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
	data->zoom = set_zoom(data);
}

float	set_zoom(t_data *data)
{
	float	zoom1;
	float	zoom2;

	if (data->width > 0 && data->width < 99)
		zoom1 = 10.0;
	else if (data->width >= 100 && data->width < 500)
		zoom1 = 2.0;
	else
		zoom1 = 1.0;
	if (data->height > 0 && data->height < 99)
		zoom2 = 10.0;
	else if (data->height >= 100 && data->height < 500)
		zoom2 = 2.0;
	else
		zoom2 = 1.0;
	if (zoom1 > zoom2)
		return (zoom2);
	else
		return (zoom1);
}
