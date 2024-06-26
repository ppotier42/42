/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:55:57 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/19 11:44:43 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	dest = malloc((sizeof (char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (dest == NULL)
		return (NULL);
	if (s1 && s2)
	{
		while (s1[i] != '\0')
		{
			dest[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			dest[i + j] = s2[j];
			j++;
		}
		dest[i + j] = '\0';
		return (dest);
	}
	return (NULL);
}

/*int main()
{
	char s1[] = "salut lou ";
	char s2[] = "comment ca va c'eset ultra long ce que je vais marque ";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/