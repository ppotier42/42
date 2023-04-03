/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/03 13:11:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_data *data, unsigned int size)
{
	unsigned int	i;
	int				swap;

	i = 0;
	swap = 0;
	while (i < (size - 1))
	{
		if (data->value[i] > data->value[i + 1])
		{
			swap = data->value[i];
			data->value[i] = data->value[i + 1];
			// ft_printf("ra\n");
			data->value[i + 1] = swap;
			printf("%d\n", data->value[i]);
			// ft_printf("pa\n");
			i = 0;
		}
		else
		{
			printf("%d\n", data->value[i]);
			i++;
		}
	}
	printf("%d\n", data->value[i]);
}
