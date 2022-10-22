/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:06:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/22 22:50:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		source = source + len - 1;
		dest = dest + len - 1;
		while (len--)
		{
				*dest-- = *source--;
		}
	}
	else if (src >= dst)
	{
		while (len--)
			*dest++ = *source++;
	}
	return (dst);
}
/*
int main()
{
	printf("expected : %s\n", memmove(((void *)0), ((void *)0), 5));
	printf("result : %s\n", ft_memmove(((void *)0), ((void *)0), 5));
}*/