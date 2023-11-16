/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:46 by ppotier           #+#    #+#             */
/*   Updated: 2023/08/24 18:06:33 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube.h"

static void	add_to_res(char **res, char *to_add)
{
	char	*tmp;

	if (to_add == NULL || ft_strlen(to_add) == 0)
		return ;
	if (*res == NULL)
	{
		*res = ft_strdup(to_add);
		return ;
	}
	tmp = *res;
	*res = ft_strjoin(*res, to_add);
	free(tmp);
	if (*res == NULL)
	{
		ft_putendl_fd("Malloc error", 2);
		exit (1);
	}
	return ;
}

char	*get_all_file(char *path)
{
	int		fd;
	char	buf[BUFFER_SIZE];
	char	*res;
	int		count;

	res = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Cannot open file", 2);
		return (NULL);
	}
	while (1)
	{
		count = read(fd, buf, BUFFER_SIZE - 1);
		buf[count] = '\0';
		add_to_res(&res, buf);
		if (count == 0)
			break ;
	}
	if (res == NULL || ft_strlen(res) == 0)
		ft_putendl_fd("File is empty", 2);
	return (res);
}
