/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:56:47 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/31 15:41:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while ((*s != '\0') && (*s != c))
	{
		s++;
	}
	if (*s == c)
	{
		return ((char *) s);
	}
	return (0);
}

/*#include <string.h>
#include <stdio.h>
int	main()
{
	char str[] = "0001000101001000111000101";
	printf ("expected : %s\n", strchr(str, '1'));
	printf("result   : %s\n", ft_strchr(str, '1'));
	return(0);
}*/