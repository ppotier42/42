/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/31 17:59:25 by ppotier          ###   ########.fr       */
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

#endif