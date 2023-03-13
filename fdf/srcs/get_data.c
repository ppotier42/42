/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/13 13:44:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_parseur(char *argv, t_data *data)
{
	int		fd;

	fd = open(argv, O_RDONLY, 0);
	get_map_height_width(fd, data);
	close(fd);
	fd = open(argv, O_RDONLY, 0);
	fill_z(data, fd);
	close(fd);
}

void	get_map_height_width(int fd, t_data *data)
{
	char	*line;

	line = get_next_line(fd);
	data->height = 0;
	data->width = ft_count_word(line, ' ');
	if (data->width == 0)
	{
		free(line);
		close(fd);
		exit(1);
	}
	while (line && (ft_count_word(line, ' ') <= data->width))
	{
		free(line);
		line = get_next_line(fd);
		data->height++;
	}
	if (line && ft_count_word(line, ' ') >= data->width)
		exit (1);
}

void	fill_z(t_data *data, int fd)
{
	char	**numb;
	char	*line;
	int		i;
	int		y;

	ft_init_data(data);
	line = get_next_line(fd);
	if (!line)
		exit(1);
	i = -1;
	while (line && ++i < data->height)
	{
		numb = ft_split(line, ' ');
		if (!numb)
			exit (1);
		y = -1;
		while (++y < data->width)
		{
			data->value[i][y] = ft_atoi(numb[y]);
			free(numb[y]);
		}
		free(line);
		free(numb);
		line = get_next_line(fd);
	}
}

void	ft_init_data(t_data *data)
{
	int	i;

	data->value = (int **)malloc(sizeof(*data->value) * (data->height));
	if (!data->value)
		exit(1);
	i = -1;
	while (++i < data->height)
	{
		data->value[i] = (int *)malloc(sizeof(*data->value[i]) * (data->width));
		if (!data->value[i])
			exit(1);
	}
}
