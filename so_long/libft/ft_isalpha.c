/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:56:09 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:58:02 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int main()
{
    int c = 'S';
    printf("result : %d", ft_isalpha(c));
	printf("\nexpected result : %d", isalpha(c));

    return(0);
}*/