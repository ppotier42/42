/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:17:54 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/15 23:04:21 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)dst;
	i = 0;
	while (i < n)
	{
		*tmp = *(char *)src;
		tmp++;
		src++;
		i++;
	}
	return (dst);
}

/*int main()
{
	char src[] = "abcdefghijkl";
	char dst[] = "je sais pas";
	printf("dst : %s\n", dst);
	printf("src : %s\n", src);
	memcpy(dst, src, 10);
	printf("expected : %s\n", dst);
	ft_memcpy(dst, src, 10);
	printf("result : %s", dst);
}*/