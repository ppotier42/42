/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:38 by ppotier           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/01/30 15:22:41 by ppotier          ###   ########.fr       */
=======
/*   Updated: 2023/01/31 17:59:25 by ppotier          ###   ########.fr       */
>>>>>>> 216be640082a204535bac26a662dcb76a7658ebf
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

<<<<<<< HEAD
typedef struct s_data {
	int			width;
	int			height;
	float		**value;
	int			zoom;
	void		*mlx;
	void		*mlx_window;
}				t_data;

typedef struct s_map {
	float	x;
	float	y;
	float	x1;
	float	y1;
	int		x_neg;
	int		y_neg;
	t_data	*data;
}	t_map;

int		main(int argc, char **argv);
void	ft_parseur(char *argv, t_data *data);
int		ft_check_fdf(char *argv);
int		get_height(char *argv);
int		get_width(char *argv);
void	fill_z(int	*value_z, char *line);
void	ft_bresenham(t_map *map, t_data *data);
void	ft_draw_line(t_data *data);
=======
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
	int			zoom;
	double		angle_x;
	double		angle_y;
	double		angle_z;
	int			shift_x;
	int			shift_y;
	double		lift;
	int			color;
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
void		ft_bresenham(t_data *data, t_vars vars);
void		draw(t_data *data, t_vars vars);
>>>>>>> 216be640082a204535bac26a662dcb76a7658ebf

#endif