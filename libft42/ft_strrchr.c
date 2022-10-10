/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:45:30 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/10 13:29:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (s[i] != c || i >= 0)
	{
		if (s[i] == c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>
int	main()
{
	char str[] = "Voir comment ca marche";
	printf ("expected : %s\n", strrchr(str, ' '));
	printf("result   : %s\n", ft_strrchr(str, ' '));
	return(0);
}*/