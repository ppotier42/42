/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:18:42 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/25 15:28:42 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*dest;

	i = 0;
	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	if (strncmp(s1, set, ft_strlen(s1)) == 0)
		return(ft_strdup(""));
	
}
