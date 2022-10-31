/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:05:53 by ppotier           #+#    #+#             */
/*   Updated: 2022/10/31 10:46:54 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_allocate(char **split, char const *s, char sep)
{
	char		**tab;
	char const	*tamp;
	size_t		i;
	size_t		j;
	size_t		k;

	k = 0;
	j = 0;
	i = 0;
	tamp = s;
	tab = split;
	while (tamp[i] != '\0')
	{
		while (s[j] == sep)
			j++;
		while (tamp[i] != '\0' && tamp[i] != sep)
			i++;
		if (tamp[i] == sep || tamp > s)
		{
			tab[k] = ft_substr(s, 0, tamp - s);
			s = tamp;
			k++;
		}
		i++;
		tab[k] = NULL;
	}
}

int	ft_mot(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = malloc ((ft_mot(s, c) + 1) * sizeof (char *));
	if (!split)
		return (NULL);
	ft_allocate(split, s, c);
	return (split);
}
/*
int main()
{
	char *s = "je comprends rien du tout";
	printf("result : %s", *ft_split(s, 'm'));
}*/