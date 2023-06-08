/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/08 15:45:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat_sleep(t_philo *philo)
{
	pthread_mutex_lock(philo->l_f);
	printf("fourhcette gauche\n");
	pthread_mutex_lock(philo->r_f);
	printf("fourhcettedroite\n");
	pthread_mutex_lock(philo->data->write);
	printf("%d, mange\n", philo->id_philo);
	// ft_usleep(philo->data->timetoeat + 1);
	pthread_mutex_unlock(philo->l_f);
	pthread_mutex_unlock(philo->r_f);
	pthread_mutex_unlock(philo->data->write);
	printf("fini\n");
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		id;

	philo = (t_philo *)arg;
	id = philo->id_philo;
	if (id % 2 == 0)
		ft_usleep(philo->data->timetoeat);
	while (philo->data->nb_meal == -1)
	{
		printf("id : %d\n", id);
		ft_eat_sleep(philo);
	}
	ft_eat_sleep(philo);
	return (NULL);
}

int	ft_create_philo(t_data *data)
{
	int		i;
	void	*philo;

	i = 0;
	philo = NULL;
	while (i < data->nb_philo)
	{
		philo = (void *)&data->p[i];
		// printf("id : %d\n", )
		printf("boucle\n");
		pthread_create(&data->thread[i], NULL, &routine, philo);
		i++;
	}
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->thread[i], NULL);
		i++;
	}
	return (0);
}

int ft_init_philo(t_data *data)
{
	int			i;
	int			start;

	i = 0;
	start = get_time();
	data->p = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->p)
		return (1);
	while (i < data->nb_philo)
	{
		data->p[i].id_philo = i + 1;
		data->p[i].data = data;
		data->p[i].time_eat = start;
		data->p[i].nb_p_eat = 0;
		data->p[i].finish = 0;
		data->p[i].l_f = &data->fork[i];
		data->p[i].r_f = &data->fork[(i + 1) % data->nb_philo];
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ft_check_args(&data, ac, av) == 1)
		return (1);
	if (data.nb_philo == 1)
		return (one_philo(data.timetodie));
	if (ft_init_philo(&data) == 1)
		return (0);
	int i = ft_create_philo(&data);
		printf("fin : %d\n", i);
	// printf("fin main\n");
	return (0);
}
