/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:25:14 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/17 16:49:14 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;

	str = (char *)b;
	i = 0;
	while (len != i)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}
/*int main () {
	char str[] = "remplacement";
	printf("debut : %s\n", ft_memset(str, 'p', 5));
	printf("fin : %s\n", memset(str, 'p', 5));
   return(0);
}*/