/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tamere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:55 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/02 15:28:25 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
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
