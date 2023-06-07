/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/07 15:23:03 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	activity(t_philo *p)
{
	printf("salope\n");
	(void)p;
	// (void)data;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	// t_data	*data;
	// int		i;
	// int		id;
	// int 	nb_meal;

	philo = (t_philo *)arg;
	// id = philo->id_philo;
	// data = philo->data;
	// nb_meal = data->nb_meal;
	// printf("%d\n", data->nb_meal);
	// i = 0;
	printf("ici\n");
	// if (id % 2 == 0)
	// 	ft_usleep(data->timetoeat + 1);
	// while (i < data->nb_meal)
	// 	{
	// 		activity(philo, data);
	// 		i++;
	// 	}
	// else
	activity(philo);
	return (NULL);
}

void	ft_init_mutex(t_philo *p)
{
	pthread_mutex_init(&p->write, NULL);
	pthread_mutex_init(&p->philo_finish, NULL);
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
		philo[i].time_eat = start;
		philo[i].nb_p_eat = 0;
		philo[i].finish = 0;
		philo[i].r_f = NULL;
		if (i == data->nb_philo - 1)
			philo[i].r_f = &philo[0].l_f;
		else
			philo[i].r_f = &philo[i + 1].l_f;
		if (pthread_create(&philo[i].thread_id, NULL, &routine, &philo[i]) != 0)
			return (NULL);
		// printf("%d : meal\n", data->nb_meal);
		i++;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_philo	*p;
	t_data	*data;

	data = ft_check_args(ac, av);
	if (data->nb_philo == 1)
	{
		one_philo(data->timetodie);
		return (0);
	}
	p = ft_init_philo(data);
	if (!p)
		free(p);
	// printf("fin main\n");
	return (0);
}
