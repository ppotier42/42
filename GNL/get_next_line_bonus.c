/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:05:54 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/20 14:25:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char static	*buff[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_gnl_read(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = ft_get_line(buff[fd]);
	buff[fd] = ft_get_clean(buff[fd]);
	return (line);
}

char	*ft_gnl_read(int fd, char *result)
{
	ssize_t	nbytes;
	char	*tmp;

	if (!result)
		result = (char *)ft_calloc(1, sizeof(char));
	tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp || !result)
		return (NULL);
	nbytes = 1;
	while (nbytes > 0)
	{
		nbytes = read(fd, tmp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(result);
			free(tmp);
			return (NULL);
		}
		tmp[nbytes] = 0;
		result = ft_strjoin(result, tmp);
		if (ft_strchr(tmp) != -1)
			break ;
	}
	free (tmp);
	return (result);
}

char	*ft_get_line(char *buff)
{
	int		i;
	char	*str;

	if (!buff[0])
		return (NULL);
	i = ft_strchr(buff);
	if (i == -1)
		i = ft_strlen(buff);
	str = ft_strndup(buff, i);
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_get_clean(char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (buff == NULL)
		return (ft_gnl_free(buff));
	i = ft_strchr(buff);
	if (i == -1)
		return (ft_gnl_free(buff));
	str = (char *)ft_calloc(ft_strlen(buff) + 1, sizeof(char));
	if (!str)
		return (ft_gnl_free(buff));
	j = 0;
	while (buff[++i])
		str[j++] = buff[i];
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*ft_gnl_free(char *buff)
{
	free(buff);
	return (NULL);
}
