/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/12 16:11:49 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *s, t_philo *philo, t_data *data)
{
	long int	time;

	time = get_time() - data->start_time;
	if (time >= 0 && time < INT_MAX)
	{
		pthread_mutex_lock(&data->write);
		printf("%ld : ", time);
		printf("Philo %d %s\n", philo->id_philo, s);
		pthread_mutex_unlock(&data->write);
	}
}

void	ft_eat_sleep_think(t_data *data, t_philo *philo)
{
	if (philo->l_f->flag_fork == 0 && philo->r_f->flag_fork == 0)
	{
		pthread_mutex_lock(&philo->l_f->mutex);
		write_status("has taken a fork", philo, data);
		philo->l_f->flag_fork = 1;
		pthread_mutex_lock(&philo->r_f->mutex);
		write_status("has taken a fork", philo, data);
		philo->r_f->flag_fork = 1;
		write_status("is eating", philo, data);
		philo->eat_count++;
		ft_usleep(data->timetoeat);
		pthread_mutex_unlock(&philo->l_f->mutex);
		philo->l_f->flag_fork = 0;
		pthread_mutex_unlock(&philo->r_f->mutex);
		philo->r_f->flag_fork = 0;
		write_status("is sleeping", philo, data);
		ft_usleep(data->timetosleep);
		write_status("is thinking", philo, data);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	if (philo->id_philo % 2 == 0)
		ft_usleep(data->timetoeat / 10);
	while (data->nb_meal == -1)
	{
		is_dead_habibi(data, philo);
		ft_eat_sleep_think(data, philo);
	}
	while (philo->eat_count < data->nb_meal)
	{
		ft_eat_sleep_think(data, philo);
	}
	return (NULL);
}

t_philo	*ft_init_philo(t_data *data)
{
	int			i;
	int			start;
	t_philo		*philo;

	i = 0;
	start = get_time();
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	while (i < data->nb_philo)
	{
		philo[i].id_philo = i + 1;
		philo[i].data = data;
		philo[i].last_meal = start;
		philo[i].eat_count = 0;
		philo[i].is_dead = 0;
		philo[i].l_f = &data->forks[i];
		philo[i].r_f = &data->forks[(i + 1) % data->nb_philo];
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (NULL);
		i++;
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

	data = ft_init_args(ac, av);
	if (data->nb_philo == 1)
		return (one_philo(data->timetodie));
	data->forks = ft_init_fork(data);
	data->p = ft_init_philo(data);
	return (0);
}
