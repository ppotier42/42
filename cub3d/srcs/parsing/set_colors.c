/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:21:53 by ppotier           #+#    #+#             */
/*   Updated: 2023/11/14 12:05:49 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

unsigned int	color_from_rgb(char r, char g, char b)
{
	unsigned int	color;
	unsigned char	*ptr;

	color = 0x00000000;
	ptr = (unsigned char *)&color;
	ptr[2] = r;
	ptr[1] = g;
	ptr[0] = b;
	return (color);
}

int	set_into_color(char *color, unsigned int *rgb)
{
	char	**split;

	split = ft_split(color, ',');
	if (!split)
		ft_exit("Split error", 2, 1);
	if (split[0] == NULL || split[1] == NULL
		|| split[2] == NULL || split[3] != NULL)
	{
		free_args(split);
		ft_exit("Wrong color format", 2, 1);
	}
	*rgb = color_from_rgb(ft_atoi(split[0]), ft_atoi(split[1]),
			ft_atoi(split[2]));
	free_args(split);
	return (0);
}

char	*get_info_id(char *id, char **lines, int first_line)
{
	int		i;
	int		found;
	char	*value;

	found = -1;
	i = -1;
	while (lines[++i] != NULL)
	{
		if (ft_strncmp(lines[i], id, ft_strlen(id)) == 0)
		{
			if (found != -1)
				ft_putendl_fd("multiple description of texture/color", 2);
			else if (i > first_line)
				ft_putendl_fd("Map not at the end of file", 2);
			if (i > first_line || found != -1)
				return (NULL);
			found = i;
		}
	}
	if (found == -1)
		ft_exit("Textures or color declaration not found", 2, 1);
	value = ft_strtrim(&lines[found][ft_strlen(id)], " ");
	if (!value)
		return (NULL);
	return (value);
}

int	set_colors(char **lines, t_map *map, int first_line)
{
	char	*floor_color;
	char	*ceiling_color;

	floor_color = get_info_id("F ", lines, first_line);
	ceiling_color = get_info_id("C ", lines, first_line);
	if (!ceiling_color || !floor_color)
	{
		free(floor_color);
		ft_putendl_fd("No ceiling color found", 2);
		return (1);
	}
	if (set_into_color(ceiling_color, &map->ceiling_color) == 1
		|| set_into_color(floor_color, &map->floor_color) == 1)
		return (1);
	free (ceiling_color);
	free(floor_color);
	return (0);
}
