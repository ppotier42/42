/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:18:08 by ppotier           #+#    #+#             */
/*   Updated: 2023/03/24 15:21:57 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(int ac, char **av)
{
	t_data	data;
	char	**args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return ;
		while (args[j])
			j++;
		data.value = (int *)malloc(sizeof(int) * j);
		if (!data.value)
			return ;
	}
	else
	{
		i = 1;
		args = av;
		data.value = (int *)malloc(sizeof(int) * ac - 1);
		if (!data.value)
			return ;
	}
	while (args[i])
	{
		data.value[i] = ft_atoi(args[i]);
		printf("%d ", data.value[i]);
		i++;
	}
	if (i <= 5)
		ft_quick_sort(data.value[i]);
	else
		ft_radix(data.value[i]);		
}

int	main(int ac, char **av)
{
	if (ac == 1)
		return (0);
	ft_check_error(ac, av);
	// printf("allo");
	ft_push_swap(ac, av);
	return (0);
}
