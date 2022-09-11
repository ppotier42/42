/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:25:06 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:59:24 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[] = "test";
	char s2[] = "tfst";
	int n = 4;
	printf("result : %d\n", ft_strncmp(s1, s2, n));
	printf("expected : %d", strncmp(s1, s2, n));
	return(0);
}*/