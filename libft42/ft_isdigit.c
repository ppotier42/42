/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:59:46 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:58:11 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = '9';
    printf("result : %d\n", ft_isdigit(c));
	printf("expected result : %d\n", isdigit(c));
	c = '1';
    printf("result : %d\n", ft_isdigit(c));
	printf("expected result : %d\n", isdigit(c));
	c = '#';
    printf("result : %d\n", ft_isdigit(c));
	printf("expected result : %d\n", isdigit(c));
	c = 'a';
    printf("result : %d\n", ft_isdigit(c));
	printf("expected result : %d\n", isdigit(c));
    return(0);
}*/
