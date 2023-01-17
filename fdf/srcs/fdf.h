/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/17 18:35:58 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_vars {
	void	*mlx;
	void	*mlx_window;
}				t_vars;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_point {
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}	t_point;

typedef struct 

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		main(int argc, char **argv);
int		ft_check_fdf(char *argv);
int		ft_init(char *argv);

#endif