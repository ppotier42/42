/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 23:19:51 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/12 19:51:19 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
		return (c);
}
/*
int main()
{
	int c = 'O';
	printf("result : %d\n", ft_tolower(c));
	printf("expected result : %d\n", tolower(c));
	c = 'J';
    printf("result : %d\n", ft_tolower(c));
	printf("expected result : %d\n", tolower(c));
	c = 'q';
    printf("result : %d\n", ft_tolower(c));
	printf("expected result : %d\n", tolower(c));
	c = 'T';
    printf("result : %d\n", ft_tolower(c));
	printf("expected result : %d\n", tolower(c));
	c = '1';
    printf("result : %d\n", ft_tolower(c));
	printf("expected result : %d\n", tolower(c));
	return(0);
}*/