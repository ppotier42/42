/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:18:26 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:58:07 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = '|';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = ' ';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = '	';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = 'a';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = 'O';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = '5';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
	c = '0';
    printf("result : %d\n", ft_isascii(c));
	printf("expected result : %d\n", isascii(c));
    return(0);
}*/