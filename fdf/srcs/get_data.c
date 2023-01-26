/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:53:43 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/24 13:41:36 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *argv)
{
	int		fd;
	char	*line;
	int		height;

	height = 0;
	fd = open(argv, O_RDONLY, 0);
	//checkfd
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

int	get_width(char *argv)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(argv, O_RDONLY, 0);
	//checkfd
	get_next_line_fdf(fd, &line);
	width = ft_count_word(line, ' ');
	free(line);
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
	while (numb[i])
	{
		value_z[i] = ft_atoi(numb[i]);
		i++;
	}
	free (numb);
}
