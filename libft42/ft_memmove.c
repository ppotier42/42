/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:06:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/27 15:12:05 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;

	dest = (char *) dst;
	source = (char *) src;
	if (source > dest)
	{
		while (len > 0)
		{
			dest[len] = source [len];
			len--;
		}
	}
	else
		return (dst);
	return (0);
}
/*
int main()
{
	char src[] = "pre";
	char dst[] = "ca marche comment";
	ft_memmove(dst, src, 4);
	printf("expected : %s\n", memmove(dst, src, 4));
	printf("result : %s", dst);
}*/