/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:38:29 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/10 14:21:34 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;

	i = ft_strlen(s1);
	j = 0;
	dst = 0;
	while (s2[j] != '\0')
	{
		dst[i] = s1[i] + s2[j];
		j++;
	}
	return (0);
}
/*
int main()
{
	char	s1[] = "aled";
	char	s2[] = "pas sur";
	printf("result : %s", ft_strjoin(s1, s2));
	return (0);
}*/