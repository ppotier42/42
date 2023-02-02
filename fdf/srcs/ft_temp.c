// // /* ************************************************************************** */
// // /*                                                                            */
// // /*                                                        :::      ::::::::   */
// // /*   ft_temp.c                                          :+:      :+:    :+:   */
// // /*                                                    +:+ +:+         +:+     */
// // /*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
// // /*                                                +#+#+#+#+#+   +#+           */
// // /*   Created: 2023/02/02 13:07:55 by ppotier           #+#    #+#             */
// // /*   Updated: 2023/02/02 13:37:42 by ppotier          ###   ########.fr       */
// // /*                                                                            */
// // /* ************************************************************************** */

// // #include "fdf.h"

// // void	set_var( int *e, int *del, int *d, int *inc)
// // {
// // 	d[0]] = 2 * e[0];
// // 	d[1] = 2 * e[1];
// // 	del[0] = e[0];
// // 	del[1] = e[1];
// // 	inc[0] = 1;
// // 	inc[1] = 1;
// // }

// // void	case_dx_dy(int *step, t_line line, t_vars *vars)
// // {
// // 	int	i;
// // 	int	del[2];
// // 	int	d[2];
// // 	int	inc[2];

// // 	i = 0;
// // 	set_var(step, del, d, inc);
// // 	if (line.x1 > line.x2)
// // 		inc[0] = -1;
// // 	if (line.y1 > line.y2)
// // 		inc[1] = -1;
// // 	while (i <= del[0])
// // 	{
// // 		pixel_2img(vars, line.x1, line.y1, 0x00FF0000);
// // 		i++;
// // 		line.x1 += inc[0];
// // 		step[0] -= d[1];
// // 		if (step[0] < 0)
// // 		{
// // 			line.y1 += inc[1];
// // 			step[0] += d[0];
// // 		}
// // 	}
// // }

// // void	case_dy_dx(int *step, t_line line, t_vars *vars
// // )
// // {
// // 	int	i;
// // 	int	del[2];
// // 	int	d[2];
// // 	int	inc[2];

// // 	i = 0;
// // 	set_var(step, del, d, inc);
// // 	if (line.x1 > line.x2)
// // 		inc[0] = -1;
// // 	if (line.y1 > line.y2)
// // 		inc[1] = -1;
// // 	while (i <= del[1])
// // 	{
// // 		pixel_2img(vars, line.x1, line.y1, 0x00FF0000);
// // 		i++;
// // 		line.y1 += inc[1];
// // 		step[1] -= d[0];
// // 		if (step[1] < 0)
// // 		{
// // 			line.x1 += inc[0];
// // 			step[1] += d[1];
// // 		}
// // 	}
// // }

// // void	draw_line(t_vars *vars, t_line line)
// // {
// // 	int	step[2];

// // 	step[0] = abs((int) line.x2 - (int) line.x1);
// // 	step[1] = abs((int) line.y2 - (int) line.y1);
// // 	if (step[0] > step[1])
// // 		case_dx_dy(step, line, &d);
// // 	else if (step[1] > step[0])
// // 		case_dy_dx(step, line, &vars);
// // }

// // void	pixel_2img(t_vars *vars, int x, int y, int color)
// // {
// // 	char	*dst;

// // 	if ((x > 0 && x <= 1920) && (y > 0 && y < 1080))
// // 	{
// // 	dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
// // 	*(unsigned int *)dst = color;
// // 	}
// // }

// #include "fdf.h"

// static void	ft_zoom_rotate(t_data *data, double *x, double *y, double z);
// static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color);

// void	draw(t_data *data, t_vars vars)
// {
// 	t_line	line;
// 	printf("draw\n");
// 	line.y1 = 0;
// 	while (line.y1++ < data->y)
// 	{
// 		line.x1 = 0;
// 		while (line.x1++ < data->x - 1)
// 		{
// 			if (line.x1 < data->y - 1)
// 			{
// 				line.x2 = line.x1 + 1;
// 				line.y2 = line.y1;
// 				ft_bresenham(data, vars, line);
// 				printf("alwedsortiex1\n");
// 			}
// 			printf("alwedmlx\n");
// 		}
// 		if (line.y1 < data->x - 1)
// 		{
// 			line.x2 = line.x1;
// 			line.y2 = line.y1 + 1;
// 			ft_bresenham(data, vars, line);
// 			printf("alwedsortiey1\n");
// 		}
// 	}
// }

// void	ft_bresenham(t_data *data, t_vars vars, t_line line)
// {
// 	double	x_step;
// 	double	y_step;
// 	double	z1;
// 	double	z2;

// 	x_step = line.x2 - line.x1;
// 	y_step = line.y2 - line.y1;
// 	line.max = fmax(fabs(x_step), fabs(y_step));
// 	x_step /= line.max;
// 	y_step /= line.max;
// 	while ((int)(line.x1 - line.x2) || (int)(line.y1 - line.y2))
// 	{
// 		printf("%d %d\n", (int)(line.x1 - line.x2), (int)(line.y1 - line.y2));
// 		my_mlx_pixel_put(&vars, (int)line.x1, (int)line.y1, 0xFF0000);
// 		line.x1 += x_step;
// 		line.y1 += y_step;
// 	}
// }

// static void	ft_zoom_rotate(t_data *data, double *x, double *y, double z)
// {
// 	double	angle;
// 	printf("zoom\n");
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

// static void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
// {
// 	char	*dst;

// 	if ((x > 0 && x <= 1920) && (y > 0 && y < 1080))
// 	{
// 		dst = vars->addr + (y * vars->line_length + x * (vars->bpp / 8));
// 		*(unsigned int *) dst = color;
// 	}
// }
