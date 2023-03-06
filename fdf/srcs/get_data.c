/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/06 16:31:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_z(int *value_z, char *line);
int		get_height(char *argv);
int		get_width(char *argv);

void	ft_parseur(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	get_map_height_width(fd, &data);
	data->value = (int **)malloc(sizeof(*data->value) * (data->height));
	if (!data->value)
		exit(-1);
	i = -1;
	while (++i < data->width)
	{
		data->value[i] = (int *)malloc(sizeof(*data->value[i]) * (data->width));
		if (!data->value[i])
			exit(-1);
	}
	fd = open(argv, O_RDONLY);
	if (!fd)
		perror ("fd problem");
	i = -1;
	while (get_next_line(fd) && ++i < data->height)
	{
		fill_z(data->value[i], line);
	}
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
	}
	while (line && ft_count_word(line, ' ') <= data->width)
	{
		free(line);
		line = get_next_line(fd);
		data->height++;
	}
	if (line && ft_count_word(line, ' ') >= data->width)
		free (line);
}

void	fill_z(int *value_z, char *line)
{
	char	**numb;
	int		i;

	numb = ft_split(line, ' ');
	if (!numb)
	{
		free(numb);
		exit(1);
	}
	i = 0;
	while (numb[i] != NULL)
	{
		value_z[i] = ft_atoi(numb[i]);
		free(numb[i]);
		i++;
	}
	free(numb);
}
