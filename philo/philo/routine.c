/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:44:48 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/19 15:48:40 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *s, t_philo *philo, t_data *data)
{
	long int	time;

	time = get_time() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (time >= 0 && time < INT_MAX && data->is_dead == 0)
	{
		printf("%ld : ", time);
		printf("Philo %d %s\n", philo->id_philo, s);
	}
	pthread_mutex_unlock(&data->write);
}

void	ft_eat_sleep_think(t_data *data, t_philo *philo)
{
	if (philo->l_f->flag_fork == 0 && philo->r_f->flag_fork == 0
		&& is_dead(data, philo) == 0)
	{
		pthread_mutex_lock(&philo->l_f->mutex);
		write_status("has taken a fork", philo, data);
		philo->l_f->flag_fork = 1;
		pthread_mutex_lock(&philo->r_f->mutex);
		write_status("has taken a fork", philo, data);
		philo->r_f->flag_fork = 1;
		philo->last_meal = get_time();
		philo->eat_count += 1;
		write_status("is eating", philo, data);
		ft_usleep(data->timetoeat, data, philo);
		pthread_mutex_unlock(&philo->l_f->mutex);
		philo->l_f->flag_fork = 0;
		pthread_mutex_unlock(&philo->r_f->mutex);
		philo->r_f->flag_fork = 0;
		write_status("is sleeping", philo, data);
		ft_usleep(data->timetosleep, data, philo);
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
		ft_usleep(data->timetoeat / 10, data, philo);
	if (data->nb_meal == -1)
	{
		while (is_dead(data, philo) == 0)
		{
			ft_eat_sleep_think(data, philo);
			if (data->is_dead == 1)
				return (NULL);
		}
		return (NULL);
	}
	else
	{
		while (philo->eat_count < data->nb_meal
			&& is_dead(data, philo) == 0)
			ft_eat_sleep_think(data, philo);
		return (NULL);
	}
	return (NULL);
}
