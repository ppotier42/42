/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 23:25:06 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/27 16:50:45 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*cp1;
	unsigned char	*cp2;

	i = 0;
	cp1 = (unsigned char *) s1;
	cp2 = (unsigned char *) s2;
	while (cp1[i] && cp2[i] && cp1[i] == cp2[i] && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return (cp1[i] - cp2[i]);
}