/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transition.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:55 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/09 14:30:37 by ppotier          ###   ########.fr       */
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