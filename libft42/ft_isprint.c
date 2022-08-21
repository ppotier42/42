/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:46:40 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/21 23:10:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < 32 || c > '~')
		return (0);
	else
		return (1);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = '~';
    printf("result : %d\n", ft_isprint(c));
	printf("expected result : %d\n", isprint(c));
	c = 't';
    printf("result : %d\n", ft_isprint(c));
	printf("expected result : %d\n", isprint(c));
	c = '	';
    printf("result : %d\n", ft_isprint(c));
	printf("expected result : %d\n", isprint(c));
	c = '>';
    printf("result : %d\n", ft_isprint(c));
	printf("expected result : %d\n", isprint(c));
	c = '?';
    printf("result : %d\n", ft_isprint(c));
	printf("expected result : %d\n", isprint(c));
    return(0);
}*/