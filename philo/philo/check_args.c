/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:58:56 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/08 14:17:52 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int		i;
	long	sum;

	sum = 0;
	i = -1;
	while (str[++i])
		sum = (sum * 10) + (str[i] - 48);
	return (sum);
}

// check si all args sont numeric et < a int_max
static int	all_numb(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9' || ft_strlen(av[i]) > 10)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check args, bien des nums etc... return (1) en reussite; 
int	ft_check_args(t_data *data, int ac, char **av)
{
	if ((ac == 5 || ac == 6) && all_numb(av))
	{
		// data = malloc(sizeof(t_data));
		// if (!data)
		// 	return (1);
		data->nb_philo = ft_atoi(av[1]);
		data->timetodie = ft_atoi(av[2]);
		data->timetoeat = ft_atoi(av[3]);
		data->timetosleep = ft_atoi(av[4]);
		if (ac == 6)
			data->nb_meal = ft_atoi(av[5]);
		else
			data->nb_meal = -1;
		if (data->nb_philo <= 0 || data->timetodie <= 0 || data->timetoeat <= 0
			|| data->timetosleep <= 0)
			return (1);
		return (0);
	}
	return (1);
}
