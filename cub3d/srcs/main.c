/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:10:51 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 12:16:47 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

t_img	*init_window(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		ft_exit("malloc error", 2, 1);
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Cube3D");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	return (img);
}

void	init_map(t_map *map)
{
	map->north_path = NULL;
	map->south_path = NULL;
	map->west_path = NULL;
	map->east_path = NULL;
	map->start_map = 0;
	map->size_x = 0;
	map->size_y = 0;
}

int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	if (ac < 2 || ac > 2)
		return (ft_putendl_fd("Format is : ./Cube3d ./map/yourmap.cub", 2), 1);
	check_path(av[1], ".cub");
	init_map(&game.map);
	if (parse_map(av[1], &game) == 1)
		return (ft_putendl_fd("Error", 2), 1);
	cube_core(&game);
	return (0);
}

int	cube_core(t_game *game)
{
	game->img = init_window();
	draw_map(game);
	mlx_hook(game->img->win, 17, 0, close_win, game);
	mlx_hook(game->img->win, 2, 0, moove_hook, game);
	mlx_loop(game->img->mlx);
	return (0);
}
