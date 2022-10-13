/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:08:46 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/13 17:17:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	tmp1 = (const unsigned char *) s1;
	tmp2 = (const unsigned char *) s2;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
			return (tmp1[i] - tmp2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char s1[] = "on compare";
	char s2[] = "on compzre";
	printf("expected : %d\n", memcmp(s1, s2, 7));
	printf("result : %d", ft_memcmp(s1, s2, 7));
	return (0);
}*/