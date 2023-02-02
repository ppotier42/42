/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_fdf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:42:26 by ppotier           #+#    #+#             */
/*   Updated: 2023/01/24 13:42:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line_fdf(int fd, char **line)
{
	char static	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_gnl_read(fd, buff);
	if (!buff)
		return (NULL);
	*line = ft_get_line(buff);
	buff = ft_get_clean(buff);
	return (*line);
}

char	*ft_gnl_read(int fd, char *result)
{
	ssize_t	nbytes;
	char	*tmp;

	if (!result)
		result = (char *)ft_calloc_gnl(1, sizeof(char));
	tmp = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
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
		result = ft_strjoin_gnl(result, tmp);
		if (ft_strchr_gnl(tmp) != -1)
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
	i = ft_strchr_gnl(buff);
	if (i == -1)
		i = ft_strlen_gnl(buff);
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
	i = ft_strchr_gnl(buff);
	if (i == -1)
		return (ft_gnl_free(buff));
	str = (char *)ft_calloc_gnl(ft_strlen_gnl(buff) + 1, sizeof(char));
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
