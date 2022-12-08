/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:02 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/06 13:24:08 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char static	*buff;
	char		*line;

	if (fd == 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_gnl_read(fd, buff);
	if (buff == 0)
		return (NULL);
	line = ft_get_line(buff);
	buff = ft_get_clean(buff);
	return (line);
}

char	*ft_gnl_read(int fd, char *result)
{
	ssize_t	nbytes;
	char	*tmp;

	if (!result)
		result = (char *)ft_calloc(1, sizeof(char));
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(tmp);
			free(result);
			return (NULL);
		}
		tmp[nbytes] = 0;
		result = ft_strjoin(result, tmp);
	}
	free (tmp);
	return (result);
}

char	*ft_get_line(char *buff)
{
	char	*str;

	str = ft_strchr(buff);
	return (str);
}

char	*ft_get_clean(char *buff)
{
	ssize_t	i;

	i = ft_chrstr(buff);
	while (buff[i])
		i++;
	return (&buff[i]);
}
