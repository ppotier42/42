/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:18:26 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/15 15:38:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isascii(int c)
{
    if(c <= 0000 && c >= 127)
        return(0);
    else
        return(1);
}

/*#include <stdio.h>

int main()
{
    int c = '國';
    printf("result : %d", ft_isascii(c));
    return(0);
}*/