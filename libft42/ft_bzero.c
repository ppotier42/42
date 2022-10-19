/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:36:27 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 13:55:27 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*int main()
{
	char str[] = "remplacement";
	printf("expected : %s\n", bzero(str, 5));
	printf("result : %s\n", ft_bzero(str, 5));
	return(0);
}*/