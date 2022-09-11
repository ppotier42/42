/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:45:34 by ppotier           #+#    #+#             */
/*   Updated: 2022/09/11 16:57:25 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	neg;

	neg = 1;
	j = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			neg *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j * neg);
}
/*#include <stdlib.h>
#include <stdio.h>

int main()
{
	char str[] = "187692334" " 70";
	printf("expected : %d\n", atoi(str));
	printf("result : %d\n", ft_atoi(str));
}*/