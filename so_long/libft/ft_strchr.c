/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:56:47 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/22 22:33:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	int				i;

	i = 0;
	str = (unsigned char *) s;
	while (str[i] != (unsigned char) c)
	{
		if (str[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return ((char *)&str[i]);
}
/*
int	main()
{
	char str[] = "teste";
	printf ("expected : %s\n", strchr(str, 'e'));
	printf("result   : %s\n", ft_strchr(str, 'e'));
	printf ("expected : %s\n", strchr("teste", '\0'));
	printf("result   : %s\n", ft_strchr("teste", '\0'));
	return(0);
}*/