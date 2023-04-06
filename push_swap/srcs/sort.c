/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:05:58 by ppotier           #+#    #+#             */
/*   Updated: 2023/04/06 14:19:01 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_quick_sort(t_data *data, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (!ft_is_sorted(data->a))
	{
		ft_printf("Is already sorted\n");
		exit (1);
	}
	while (i < (size - 1))
	{
		if (data->a[i] > data->a[i + 1])
		{
			data->b[i] = data->a[i];
			ft_printf("pb\n");
			data->a[i] = data->a[i + 1];
			ft_printf("ra\n");
			data->a[i + 1] = data->b[i];
			// printf("%d\n", data->value[i]);
			ft_printf("pa\n");
			i = 0;
		}
		else
		{
			// printf("%d\n", data->value[i]);
			i++;
		}
	}
	// printf("%d\n", data->a[i]);
}
