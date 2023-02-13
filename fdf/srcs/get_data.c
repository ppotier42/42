/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/13 18:49:45 by ppotier          ###   ########.fr       */
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

	data->y = get_height(argv);
	data->x = get_width(argv);
	data->value = (int **)malloc(sizeof(*data->value) * (data->y));
	if (!data->value)
		exit(-1);
	i = -1;
	while (++i < data->x)
	{
		data->value[i] = (int *)malloc(sizeof(*data->value) * (data->x));
		if (!data->value)
			exit(-1);
	}
	fd = open(argv, O_RDONLY);
	if (!fd)
		perror ("fd problem");
	i = -1;
	while (get_next_line_fdf(fd, &line) && ++i < data->y)
	{
		fill_z(data->value[i], line);
		free(line);
	}
	close(fd);
}

int	get_height(char *argv)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(argv, O_RDONLY, 0);
	if (!fd || fd == -1)
		return (0);
	while (get_next_line_fdf(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *argv)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(argv, O_RDONLY, 0);
	if (!fd || fd == -1)
		return (0);
	while (get_next_line_fdf(fd, &line))
	{
		width = ft_count_word(line, ' ');
		free(line);
	}
	close(fd);
	return (width);
}

void	fill_z(int *value_z, char *line)
{
	char	**numb;
	int		i;

	numb = ft_split(line, ' ');
	if (!numb)
		numb = NULL;
	i = 0;
	while (numb[i + 1] != NULL)
	{
		value_z[i] = ft_atoi(numb[i]);
		free (numb[i]);
		i++;
	}
	free (numb[i]);
}
