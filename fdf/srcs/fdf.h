/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/13 13:28:26 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../mlxOS/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_vars;

typedef struct s_data {
	float		x;
	float		y;
	int			**value;
	float		zoom;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	int			shift_x;
	int			shift_y;
	double		lift;
	int			color;
	int			size_x;
	int			size_y;
}				t_data;

typedef struct s_line {
	double	x1;
	double	y1;
	double	x2;
	double	y2;
	double	max;
}			t_line;

int			main(int argc, char **argv);
int			ft_error(int argc);
void		ft_parseur(char *argv, t_data *data);
int			ft_check_fdf(char *argv);
void		ft_horizon(t_data *data, t_vars *vars);
void		ft_zoom_rotate(t_data *data, double *x, double *y, double z);
void		ft_vertical(t_data *data, t_vars *vars);
void		draw_segment(t_vars *vars, t_data *data, t_line line);
void		set_var(int *e, int *del, int *d, int *inc);
int			close_win(int keycode, t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
void		ft_set_map(t_data *data);
void		set_window_size(t_data *data);
float		set_zoom(t_data *data);

#endif