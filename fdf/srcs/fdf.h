/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:16:38 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/20 17:09:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_data {
	int		width;
	int		height;
	int		**value;
	int		zoom;
	void	*mlx;
	void	*mlx_window;
}				t_data;

int		main(int argc, char **argv);
void	ft_parseur(char *argv, t_data *data);
int		ft_check_fdf(char *argv);
int		get_height(char *argv);
int		get_width(char *argv);
void	fill_z(int	*value_z, char *line);
void	ft_bresenham(float x, float y, float x1, float y1, t_data *data);
void	ft_draw_line(t_data *data);

#endif