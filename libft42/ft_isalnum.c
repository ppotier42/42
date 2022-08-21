/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:05:06 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/21 22:44:50 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = 'Z';
    printf("result : %d \n", ft_isalnum(c));
	printf("expected result : %d", isalnum(c));
    return(0);
}