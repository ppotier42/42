/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:48:27 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 12:12:46 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

int	find_first_map_line(char **lines)
{
	int	i;

	i = 0;
	while (lines[i] != NULL)
	{
		if (is_in_charset(lines[i][0], " 10"))
			return (i);
		i++;
	}
	ft_putendl_fd("No map found", 2);
	return (-1);
}

int	parse_lines(char **lines, t_game *game)
{
	int	map_first_line;

	map_first_line = find_first_map_line(lines);
	if (map_first_line == -1)
		return (1);
	if (set_colors(lines, &game->map, map_first_line) == 1)
		return (1);
	if (set_textures(lines, game, map_first_line) == 1)
		return (1);
	if (set_map(&lines[map_first_line], game) == 1)
		return (1);
	return (0);
}

int	go_to_map(char *path, char **line, int *fd)
{
	*fd = open(path, O_RDONLY);
	if (*fd == -1)
		return (1);
	while (1)
	{
		*line = get_next_line(*fd);
		if (*line == NULL)
			break ;
		if (is_in_charset((*line)[0], " 01"))
		{
			free(*line);
			break ;
		}
		free(*line);
	}
	return (0);
}

int	is_map_compact(char *path)
{
	char	*line;
	int		has_empty;
	int		fd;

	if (go_to_map(path, &line, &fd) == 1)
		return (0);
	has_empty = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (has_empty && line[0] != '\n' && line[1] != '\0')
		{
			free(line);
			return (0);
		}
		if (line[0] == '\n')
			has_empty = 1;
		free(line);
	}
	return (1);
}

int	parse_map(char *path, t_game *game)
{
	char	*file_content;
	char	**lines;

	file_content = get_all_file(path);
	if (file_content == NULL || ft_strlen(file_content) == 0)
		return (1);
	if (is_map_compact(path) == 0)
	{
		free(file_content);
		ft_putendl_fd("Map has an empty line", 2);
		return (1);
	}
	lines = ft_split(file_content, '\n');
	free(file_content);
	if (!lines)
		ft_exit("malloc error", 2, 1);
	if (parse_lines(lines, game) == 1)
	{
		free_args(lines);
		return (1);
	}
	free_args(lines);
	map_to_int(game);
	return (0);
}
