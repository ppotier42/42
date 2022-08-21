/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:59:46 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/21 22:59:49 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
