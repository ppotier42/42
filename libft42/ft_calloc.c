/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 11:50:50 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/24 12:07:37 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (void *)malloc(count * size);
	if (str == NULL)
		return (str);
	while (i < size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
/*
int main()
{
	printf("result : %p\n", ft_calloc(4, 5));
	printf("expected : %p\n", calloc(4, 5));
}*/