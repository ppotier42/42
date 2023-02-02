/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/02/02 17:24:03 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fill_z(int *value_z, char *line);
static int	get_height(char *argv);
static int	get_width(char *argv);

void	ft_parseur(char *argv, t_data *data)
{
	int		fd;
	char	*line;
	int		i;

	data->y = get_height(argv);
	data->x = get_width(argv);
	data->value = (int **)malloc(sizeof(int *) * (data->x + 1));
	i = 0;
	while (i <= data->x)
		data->value[i++] = (int *)malloc(sizeof(int) * (data->y + 1));
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line_fdf(fd, &line))
	{
		fill_z(data->value[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->value[i] = NULL;
}

static int	get_height(char *argv)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(argv, O_RDONLY, 0);
	if (!fd)
		return (0);
	if (fd == -1)
		return (0);
	while (get_next_line_fdf(fd, &line))
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	get_width(char *argv)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(argv, O_RDONLY, 0);
	if (!fd)
		return (0);
	get_next_line_fdf(fd, &line);
	width = ft_count_word(line, ' ');
	free(line);
	close(fd);
	return (width);
}

static void	fill_z(int *value_z, char *line)
{
	char	**numb;
	int		i;

	numb = ft_split(line, ' ');
	if (!numb)
		numb = NULL;
	i = 0;
	while (numb[i] != NULL)
	{
		value_z[i] = ft_atoi(numb[i]);
		i++;
	}
	free (numb);
}
