/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:06:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/24 15:25:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*source;

	i = 0;
	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (len == 0)
		return (dest);
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (len--)
				dest[len] = source[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
	printf("expected : %s\n", memmove(((void *)0), ((void *)0), 5));
	printf("result : %s\n", ft_memmove(((void *)0), ((void *)0), 5));
}*/