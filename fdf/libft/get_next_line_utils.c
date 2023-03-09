// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/23 10:44:04 by ppotier           #+#    #+#             */
// /*   Updated: 2023/03/09 11:54:41 by ppotier          ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "libft.h"

// void	*ft_calloc_gnl(size_t count, size_t size)
// {
// 	void			*str;
// 	size_t			i;
// 	unsigned char	c;

// 	str = malloc(count * size);
// 	if (!str)
// 		return (NULL);
// 	c = '\0';
// 	i = 0;
// 	while (i < (count * size))
// 	{
// 		((char *)str)[i] = c;
// 		i++;
// 	}
// 	return (str);
// }

// char	*ft_strjoin_gnl(char *s1, char *s2)
// {
// 	size_t		i;
// 	size_t		j;
// 	char		*c;
// 	size_t		tlen;

// 	tlen = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	c = (char *)ft_calloc(tlen, sizeof(char));
// 	if (!c)
// 		free(s1);
// 	if (!c)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (s1[i] != '\0')
// 	{
// 		c[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 		c[i++] = s2[j++];
// 	free (s1);
// 	c[i] = '\0';
// 	return (c);
// }

// size_t	ft_strlen_gnl(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// int	ft_strchr_gnl(char *buff)
// {
// 	size_t	i;

// 	i = 0;
// 	while (buff[i])
// 	{
// 		if (buff[i] == '\n')
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// char	*ft_strndup_gnl(char *buff, size_t end)
// {
// 	char		*s2;
// 	size_t		i;

// 	i = 0;
// 	s2 = (char *)ft_calloc(end + 2, sizeof(char));
// 	if (!s2)
// 		return (NULL);
// 	while (i <= end)
// 	{
// 		s2[i] = buff[i];
// 		i++;
// 	}
// 	s2[i] = '\0';
// 	return (s2);
// }

#include "libft.h"

char	*get_ndup(char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*cp;

	if (!s)
		return (NULL);
	len = get_len(s);
	if (len > n)
		len = n;
	i = 0;
	cp = ft_calloc(sizeof(*cp), (len + 1));
	if (!cp)
		return (NULL);
	while (i < len)
	{
		*(cp + i) = *(s + i);
		i++;
	}
	*(cp + i) = '\0';
	return (cp);
}

char	*get_join(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*dest;
	size_t	i;

	i = 0;
	l1 = get_len(s1);
	l2 = get_len(s2);
	dest = ft_calloc(sizeof(*dest), (l1 + l2 + 1));
	if (!dest)
		return (NULL);
	while (i < l1)
	{
		dest[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < l2)
	{
		dest[l1 + i] = s2[i];
		i++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}

int	get_next_c(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	else
		return (0);
}	

int	get_len(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	void	*res;
// 	size_t	n;
// 	size_t	i;

// 	n = size * nmemb;
// 	res = malloc(n);
// 	if (!res)
// 		return (NULL);
// 	i = 0;
// 	while (i < n)
// 	{
// 		*(unsigned char *)(res + i) = '\0';
// 		i++;
// 	}
// 	return (res);
// }