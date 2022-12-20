/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:04 by ppotier           #+#    #+#             */
/*   Updated: 2022/12/12 16:09:09 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*str;
	size_t			i;
	unsigned char	c;

	str = malloc(count * size);
	if (!str)
		return (NULL);
	c = '\0';
	i = 0;
	while (i < (count * size))
	{
		((char *)str)[i] = c;
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		i;
	size_t		j;
	char		*c;
	size_t		tlen;

	tlen = ft_strlen(s1) + ft_strlen(s2) + 1;
	c = (char *)ft_calloc(tlen, sizeof(char));
	if (!c)
		free(s1);
	if (!c)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		c[i++] = s2[j++];
	free (s1);
	c[i] = '\0';
	return (c);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *buff, size_t end)
{
	char		*s2;
	size_t		i;

	i = 0;
	s2 = (char *)ft_calloc(end + 2, sizeof(char));
	if (!s2)
		return (NULL);
	while (i <= end)
	{
		s2[i] = buff[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
