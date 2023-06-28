/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:44:48 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/28 15:40:40 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *s, t_philo *philo, t_data *data)
{
	long int	time;

	time = get_time() - data->start_time;
	pthread_mutex_lock(&data->write);
	if (time >= 0 && time < INT_MAX)
	{
		printf("%ld : ", time);
		printf("Philo %d %s\n", philo->id_philo, s);
	}
	pthread_mutex_unlock(&data->write);
}

void	ft_think(t_data *data, t_philo *philo)
{
	if (data->is_dead == 0)
	{
		printf("pense\n");
		is_dead(data, philo);
	}
}

void	ft_eat_sleep_think(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->r_f->mutex);
	write_status("has taken a fork", philo, data);
	pthread_mutex_lock(&philo->l_f->mutex);
	write_status("has taken a fork", philo, data);
	philo->eat_count += 1;
	write_status("is eating", philo, data);
	philo->last_meal = get_time();
	ft_usleep(data->timetoeat, data, philo);
	pthread_mutex_unlock(&philo->l_f->mutex);
	pthread_mutex_unlock(&philo->r_f->mutex);
	write_status("is sleeping", philo, data);
	ft_usleep(data->timetosleep, data, philo);
	write_status("is thinking", philo, data);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->id_philo % 2 == 0)
		ft_usleep(p->data->timetoeat / 10, p->data, p);
	if (p->data->nb_meal == -1)
	{
		while (is_dead(p->data, p) == 0)
		{
			if (p->data->is_dead == 0)
				ft_eat_sleep_think(p->data, p);
			if (p->data->is_dead == 1)
				return (NULL);
		}
		return (NULL);
	}
	else
	{
		while (p->eat_count < p->data->nb_meal && is_dead(p->data, p) == 0)
		{
			ft_eat_sleep_think(p->data, p);
			if (p->data->is_dead == 1)
				return (NULL);
		}
		return (NULL);
	}
}
