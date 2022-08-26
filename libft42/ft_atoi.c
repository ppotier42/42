/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <pierre.podnieks@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 22:45:34 by ppotier           #+#    #+#             */
/*   Updated: 2022/08/25 22:57:10 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = str[i] + 42;
		i++;
	}
	return (*str);
}*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
	char str[] = "102030";
	printf("expected : %d\n", atoi(str));
	//printf("result : %d\n", ft_atoi(str));
}