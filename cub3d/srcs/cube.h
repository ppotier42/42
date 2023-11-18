/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:25:18 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/15 17:03:59 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

// #define mapX  8      //map width
// #define mapY  8      //map height
// #define maps 64      //map cube size
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlxOS/mlx.h"
# include "../libft/libft.h"
# define MINIMAP 16
# define NBR_RAYS 512
# define DEG 0.0174533
# define PI 3.1415926535
# define PI2 1.57079632679
# define PI3 4.71238898038
# define CUBSIZE 64
# define RT_SPEED 0.45
# define MOVESPEED 0.60
# define WIDTH 1024
# define HEIGHT 512

struct	s_wall_textures;

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef enum e_dir {
	NORTH = 0,
	EAST = 1,
	WEST = 2,
	SOUTH = 3
}	t_dir;

typedef struct s_var
{
	int		dof;
	double	rx;
	double	ry;
	double	ra;
	double	xo;
	double	yo;
	double	atan;
}	t_var;

typedef struct s_img {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		win_w;
	int		win_h;
	int		color;
	float	px;
	float	py;
	int		img_w;
	int		img_h;	
	int		width;
	int		height;
	int		tex_w;
	int		tex_h;
}	t_img;

typedef struct s_wall_textures {
	t_img	north;
	t_img	south;
	t_img	west;
	t_img	east;
}	t_wall_textures;

typedef struct s_map
{
	char			**map;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	unsigned int	ceiling_color;
	unsigned int	floor_color;
	int				*map_int;
	t_vec			dir[4];
	t_vec			playerdir;
	double			pangle;
	double			pangle2;
	double			player_pos_x;
	double			player_pos_y;
	double			mini_player_pos_x;
	double			mini_player_pos_y;
	int				size_x;
	int				size_y;
	int				start_map;
	t_wall_textures	textures;
	int				wall_c;
	int				empty_c;
}	t_map;

typedef struct s_game {
	int			height;
	int			width;
	int			dist;
	int			flag;
	int			dwall_n;
	int			dwall_s;
	int			dwall_e;
	int			dwall_w;
	t_img		xpm_img[4];
	char		*img_data;
	int			xpm_height;
	int			xpm_width;
	double		playerdist;
	double		lineh;
	double		lineo;
	int			ax;
	int			r;
	int			scl_fct;
	float		fish;
	t_img		*pic;
	t_img		*img;
	t_img		*mini_img;
	t_map		map;
	t_var		var;
}	t_game;

// main.c
int		main(int ac, char **av);
int		cube_core(t_game *game);
void	init_game(t_map *map);
// parse.c
int		parse_map(char *path, t_game *game);
// get_file.c
char	*get_all_file(char *path);
// set_colors.c
int		set_colors(char **lines, t_map *map, int first_line);
char	*get_info_id(char *id, char **lines, int first_line);
// utils.c
void	ft_exit(char *str, int fd, int exit_status);
void	check_path(char *path, char *file);
void	deallocate_map(t_map *map);
// set_textures.c
int		set_textures(char **lines, t_game *game, int first_line);
//render_walls.c
t_img	load_textures(t_game *game, char *path);
int		get_pixel_color(t_img *img, int x, int y);
// set map.c
int		set_map(char **lines, t_game *game);
// check_map.c
int		check_map(char **lines);
// chech_surrounding.c
int		check_surrounding(t_map *map);
// ft_fill_value.c
void	ft_init_map(t_map *map);
//game.c
// void	draw_map(t_game *game);

//key_hooks.c
int		close_win(int keycode, t_game *game);
int		moove_hook(int keycode, t_game *game);
void	map_to_int(t_game *game);

//Minimap
//draw_mini_player.c
int		draw_map(t_game *game);
void	draw_mini_player(t_game *game);
void	render_map(t_game *game);
void	check_angle(t_game *game);
void	draw_floor(t_game *game);
void	draw_ceiling(t_game *game);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	check_wall(t_game *game);
float	check_horizontal(t_game *game, int flag);
float	check_vertical(t_game *game, int flag);
void	print_wall(t_game *game, double truc, int y, int wall);
void	ra_to_pi(t_game *game, t_var *var);
int		ft_calcul(t_game *game, t_var *var, int flag, int flag2);

#endif