/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:45:34 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 16:14:33 by ppotier          ###   ########.fr       */
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
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = j * 10 + (str[i] - '0');
		i++;
	}
	return (j * neg);
}
/*
int main()
{
	char str[] = "\t\n\r\v\f  469 \n";
	printf("expected : %d\n", atoi(str));
	printf("result : %d\n", ft_atoi(str));
	printf("expected : %d\n", atoi("--47"));
	printf("result : %d\n", ft_atoi("--47"));
	printf("expected : %d\n", atoi("-+48"));
	printf("result : %d\n", ft_atoi("-+48"));
}*/