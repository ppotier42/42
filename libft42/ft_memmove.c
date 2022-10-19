/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 23:06:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 14:14:05 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *) dst;
	source = (char *) src;
	i = 0;
	if (source > dest)
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
	{
		while (i != len)
		{
			dest[len - i - 1] = source[len - i - 1];
			i++;
		}
	}
	return (dst);
}
/*
int main()
{
	char src[] = "donc si le mot est long";
	char dst[] = "du coup ca remplace paro";
	printf("expected : %s\n", memmove(dst, src, 24));
	printf("result : %s\n", ft_memmove(dst, src, 24));
}*/