/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 16:25:14 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:58:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;

	str = b;
	while (len > 0)
	{
		*str = c;
		str++;
		len--;
	}
	return (b);
}
/*int main () {
	char str[] = "remplacement";
	printf("debut : %s\n", str);
	ft_memset(str, '~', 13);
	printf("fin : %s\n", str);
   return(0);
}*/