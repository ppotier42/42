/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:59:46 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/15 15:09:32 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isdigit(int c)
{
    if(c < '0' || c > '9')
        return(0);
    else
        return(1);
}

/*#include <stdio.h>
int main()
{
    int c = '9';
    printf("result : %d", ft_isdigit(c));
    return(0);
}*/