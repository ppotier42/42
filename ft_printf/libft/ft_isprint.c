/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:46:40 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:58:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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