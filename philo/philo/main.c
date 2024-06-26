/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/21 14:39:20 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_stop(t_data *data)
{
	int		i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->dead);
	pthread_mutex_destroy(&data->write);
	return ;
}

t_philo	*ft_init_philo(t_data *data)
{
	int			i;
	t_philo		*philo;

	i = -1;
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	while (++i < data->nb_philo)
	{
		philo[i].id_philo = i + 1;
		philo[i].data = data;
		philo[i].last_meal = get_time();
		philo[i].eat_count = 0;
		philo[i].l_f = &data->forks[i];
		philo[i].r_f = &data->forks[(i + 1) % data->nb_philo];
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (NULL);
	}
	i = -1;
	while (++i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (NULL);
	}
	return (philo);
}

t_fork	*ft_init_fork(t_data *data)
{
	t_fork	*fork;
	int		i;

	i = 0;
	fork = malloc(sizeof(t_fork) * data->nb_philo);
	if (!fork)
		return (NULL);
	while (i < data->nb_philo)
	{
		fork[i].flag_fork = 0;
		i++;
		if (pthread_mutex_init(&fork[i].mutex, NULL) != 0)
			return (NULL);
	}
	return (fork);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (all_numb(av) || ac < 5 || ac > 6)
		return ((printf("False arguements\n")), 0);
	data = ft_init_args(ac, av);
	if (data->nb_philo == 1)
		return (one_philo(data->timetodie));
	data->forks = ft_init_fork(data);
	data->p = ft_init_philo(data);
	if (data->nb_meal == data->p->eat_count)
		printf("Philosophers ate %d times\n", data->p->eat_count);
	ft_stop(data);
	free(data->forks);
	free(data);
	free(data->p);
	return (0);
}
