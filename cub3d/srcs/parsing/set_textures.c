/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:00:06 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 11:57:47 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

t_img	load_textures(t_game *game, char *path)
{
	t_img	xpm_img;

	xpm_img.img = mlx_xpm_file_to_image(game, path,
			&xpm_img.win_w, &xpm_img.win_h);
	if (!xpm_img.img)
		ft_exit("Cannot load image", 2, 1);
	xpm_img.addr = mlx_get_data_addr(xpm_img.img,
			&xpm_img.bpp, &xpm_img.line_length,
			&xpm_img.endian);
	if (!xpm_img.img)
		ft_exit("Cannot get image data", 2, 1);
	return (xpm_img);
}

static int	is_valid_path(char *path)
{
	int	fd;

	check_path(path, ".xpm");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_exit("Cannot open .xpm file", 2, 1);
	close(fd);
	return (1);
}

static int	set_textures_path(char **lines, t_game *game, int first_line)
{
	game->map.north_path = get_info_id("NO ", lines, first_line);
	if (!game->map.north_path)
		return (1);
	game->map.south_path = get_info_id("SO ", lines, first_line);
	if (!game->map.south_path)
		return (1);
	game->map.west_path = get_info_id("WE ", lines, first_line);
	if (!game->map.west_path)
		return (1);
	game->map.east_path = get_info_id("EA ", lines, first_line);
	if (!game->map.east_path)
		return (1);
	if (!is_valid_path(game->map.north_path)
		|| !is_valid_path(game->map.south_path)
		||!is_valid_path(game->map.west_path)
		|| !is_valid_path(game->map.east_path))
		ft_exit("Cannot open textures files", 2, 1);
	game->xpm_img[0] = load_textures(game, game->map.north_path);
	game->xpm_img[1] = load_textures(game, game->map.south_path);
	game->xpm_img[2] = load_textures(game, game->map.west_path);
	game->xpm_img[3] = load_textures(game, game->map.east_path);
	return (0);
}

int	set_textures(char **lines, t_game *game, int first_line)
{
	if (set_textures_path(lines, game, first_line) == 1)
		return (1);
	return (0);
}
