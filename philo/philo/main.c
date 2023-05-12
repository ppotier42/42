/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/12 13:51:12 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_get_time(char **av)
{
	struct timeval te;
	(void)av;
	// (void)data;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec*1000LL + te.tv_usec/1000; // calculate milliseconds
    printf("milliseconds: %lld\n", milliseconds);
}

// struct philo, struct table struct data ? 
void	ft_init_philo(int ac, char **av)
{
	(void)ac;
	// t_data	*data;
	// t_philo	*philo;
	// t_table	*table;

	ft_get_time(av);
	// philo->philo = atoi(av[1]);
	// data->timetodie = gettimeofday(av[2]);
	// data->timetoeat = ft_atoi(av[3]);
	// data->timetosleep = ft_atoi(av[4]);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		if (ac < 5)
			ft_putstr_error("Not enough args", 1);
		else
			ft_putstr_error("Too many args", 1);
		return (0);
	}
	ft_init_philo(ac, av);
	return (0);
}