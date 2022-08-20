/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 15:46:40 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/15 15:51:41 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isprint(int c)
{
    if(c < ' ' && c > '~')
        return(0);
    else
        return(1);
}

/*#include <stdio.h>
int main()
{
    int c = '~';
    printf("result : %d", ft_isprint(c));
    return(0);
}*/