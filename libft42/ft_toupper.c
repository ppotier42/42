/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:56:18 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/21 23:17:51 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
		return (c);
}
/*#include <stdio.h>
#include <ctype.h>

int main()
{
	int c = 'o';
	printf("result : %d\n", ft_toupper(c));
	printf("expected result : %d\n", toupper(c));
	c = 'J';
    printf("result : %d\n", ft_toupper(c));
	printf("expected result : %d\n", toupper(c));
	c = 'q';
    printf("result : %d\n", ft_toupper(c));
	printf("expected result : %d\n", toupper(c));
	c = 'T';
    printf("result : %d\n", ft_toupper(c));
	printf("expected result : %d\n", toupper(c));
	c = '1';
    printf("result : %d\n", ft_toupper(c));
	printf("expected result : %d\n", toupper(c));
	return(0);
}*/