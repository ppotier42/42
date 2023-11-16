/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:31:07 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/16 11:59:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static int	set_player(int i, int j, t_game *game, char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (c == 'N')
			game->map.pangle = PI * 1.5;
		else if (c == 'S')
			game->map.pangle = 0.5 * PI;
		else if (c == 'W')
			game->map.pangle = PI;
		else if (c == 'E')
			game->map.pangle = 2 * PI;
		game->map.player_pos_x = CUBSIZE * j + CUBSIZE / 2;
		game->map.player_pos_y = CUBSIZE * i + CUBSIZE / 2;
		game->map.playerdir.x = cos(game->map.pangle) * 5;
		game->map.playerdir.y = sin(game->map.pangle) * 5;
		return (0);
	}
	return (1);
}

static int	fill_map(char **lines, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (++j < game->map.size_x)
		{
			if (lines[i][j] == '0')
				game->map.map[i][j] = '0';
			else if (lines[i][j] == '1')
				game->map.map[i][j] = '1';
			else if (lines[i][j] == '\0')
				j++;
			else if (is_in_charset(lines[i][j], "NSWE"))
			{
				game->map.map[i][j] = '0';
				set_player(i, j, game, lines[i][j]);
			}
			else
				game->map.map[i][j] = '2';
		}
	}
	return (0);
}

static void	allocate_map(t_map *map)
{
	int	i;

	map->map = (char **)malloc(sizeof(char *) * map->size_y);
	if (!map->map)
		ft_exit("Malloc error", 2, 1);
	i = 0;
	while (i < map->size_y)
	{
		map->map[i] = (char *)ft_calloc(sizeof(char), map->size_x + 1);
		if (!map->map[i])
			ft_exit("Malloc error", 2, 1);
		i++;
	}
}

void	set_map_size(char **lines, t_map *map)
{
	int	largest;
	int	i;

	largest = 0;
	i = 0;
	while (lines[map->size_y] != NULL)
		map->size_y++;
	while (lines[i] != NULL)
	{
		if (ft_strlen(lines[i]) > largest)
			largest = ft_strlen(lines[i]);
		i++;
	}
	map->size_x = largest;
	map->size_y = i;
}

int	set_map(char **lines, t_game *game)
{
	if (check_map(lines) == 0)
		return (0);
	set_map_size(lines, &game->map);
	if (game->map.size_x == 0 || game->map.size_y == 0)
		return (0);
	allocate_map(&game->map);
	fill_map(lines, game);
	if (check_surrounding(&game->map) == 1)
		return (1);
	return (0);
}
