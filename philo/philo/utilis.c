/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:46:29 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/28 15:39:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_data *data, t_philo *philo)
{
	long int	time;

	time = get_time();
	pthread_mutex_lock(&data->dead);
	if (time - philo->last_meal > data->timetodie)
	{
		data->is_dead = 1;
		pthread_mutex_lock(&data->write);
		printf("%ld : ", time - philo->last_meal);
		printf("Philo %d died\n", philo->id_philo);
		pthread_mutex_unlock(&data->write);
		return (1);
	}
	pthread_mutex_unlock(&data->dead);
	return (0);
}

void	ft_putstr_error(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

long int	get_time(void)
{
	struct timeval	te;
	long int		time;

	if (gettimeofday(&te, NULL) == -1)
		return (-1);
	time = (te.tv_sec * 1000) + (te.tv_usec / 1000);
	return (time);
}

int	ft_usleep(useconds_t time, t_data *data, t_philo *philo)
{
	long int	start;

	start = get_time();
	while ((get_time() - start) < time && is_dead(data, philo) == 0)
		usleep(time / 10);
	return (0);
}
