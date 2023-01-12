/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:17:54 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 20:13:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)dst;
	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*tmp = *(char *)src;
		tmp++;
		src++;
		i++;
	}
	return (dst);
}
