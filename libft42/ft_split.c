/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:05:53 by ppotier           #+#    #+#             */
/*   Updated: 2022/11/01 15:56:15 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (word);
}

int	ft_size(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i] != '\0')
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		word;
	int		size;

	i = 0;
	j = -1;
	word = ft_count(s, c);
	str = (char **)malloc((word + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < word)
	{
		while (s[i] == c)
			i++;
		size = ft_size(s, c, i);
		str[j] = ft_substr(s, i, size);
		if (!str[j])
			free(str);
		i = i + size;
	}
	str[j] = 0;
	return (str);
}
/*
int main()
{
	printf("result : %s", *ft_split("je comprends rien du tout", 'q'));
	printf("\n");
	printf("result : %s", *ft_split("je comprends rien du tout", 'j'));
	printf("\n");
	printf("result : %s", *ft_split("je comprends rien du tout", 'u'));
	printf("\n");
	printf("result : %s", *ft_split("je comprends rien du tout", 'i'));
	printf("\n");
}*/