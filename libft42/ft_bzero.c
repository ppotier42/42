/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:36:27 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/26 22:19:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
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

void	ft_bzero(void *b, unsigned long n)
{
	ft_memset(b, '0', n);
}

/*#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "remplacement";
	printf("debut : %s\n", str);	
	//printf("expected : %d\n", *bzero(str, 5));
	ft_bzero(str, 15);
	printf("result : %s\n", str);
	return(0);
}*/