/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:45:30 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/01 21:58:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	while (*s != '\0')
	{
		s++;
	}
	while (*s != c || *s > 0)
	{
		if (*s == c)
			return ((char *) s);
		s--;
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int	main()
{
	char str[] = "Voir comment ca marche";
	printf ("expected : %s\n", strrchr(str, 'h'));
	printf("result   : %s\n", ft_strrchr(str, 'h'));
	return(0);
}*/