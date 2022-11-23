/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 10:44:04 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/23 18:14:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	n = count * size;
	str = malloc(n);
	if (!str)
		return (NULL);
	while (i != n)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (!c)
		return (NULL);
	if (s1 && s2)
	{
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
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			return (buff[i]);
		}
		i++;
	}
	return (0);
}

int	ft_chrstr(char *buff)
{
	size_t	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (0);
}