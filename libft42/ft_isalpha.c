/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:56:09 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/20 17:21:26 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main()
{
    int c = '[';
    printf("result : %d", ft_isalpha(c));
    return(0);
}*/