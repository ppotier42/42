/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:37:04 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 13:13:27 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	char	*p_src;

	j = 0;
	i = 0;
	p_src = (char *)src;
	while (i < dstsize)
	{
		if (dst[i] == 0)
			break ;
		if (i == dstsize - 1 && dst[i])
			return (dstsize + ft_strlen(src));
	++i;
	}
	i = ft_strlen(dst);
	while (i + j < dstsize - 1 && p_src[j] && 0 < dstsize)
	{
		dst[i + j] = p_src[j];
		++j;
	}
		dst[i + j] = 0;
	if (dstsize < i)
		return (dstsize + ft_strlen(src));
	return (i + ft_strlen(src));
}

/*int main()
{
	char src[] = "commentcamarche";
	char dest[] = "toujourspascompris";
	printf("result :%zu\n", ft_strlcat(dest, src, 20));
	printf("expected :%lu\n", strlcat(dest, src, 20));
	return(0);
}*/