/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 22:56:18 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/10 16:47:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
		return (c);
}
/*
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