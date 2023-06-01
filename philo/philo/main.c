/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/01 15:48:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_init_philo(t_data *data, t_philo *philo)
{
	int			i;
	int			start;
	// pthread_t	t0;

	i = 0;
	start = get_time();
	philo = malloc(sizeof(t_philo) * data->nb_philo);
	if (!philo)
		return (NULL);
	printf("nbphilo : %d\n", data->nb_philo);
	while (i < data->nb_philo)
	{
		printf("i : %d\n", i);
		philo[i].id_philo = i + 1;
		philo[i].time_eat = start;
		philo[i].nb_p_eat = 0;
		printf("id philo : %d\n", philo[i].id_philo);
		i++;
		// printf("id philo : %d\n", philo->id_philo);
		printf("time_to_eat : %d\n", start);
	}
	printf("fin philo\n");
	return (philo);
}

int	main(int ac, char **av)
{
	t_data	data;
	t_philo	philo;
	t_philo	*p;

	if (!(ft_check_args(ac, av, &data)))
		return (ft_putstr_error("Invalid args", 2), 1);
	if (data.nb_philo == 1)
	{	
		one_philo(data.timetodie);
		return (0);
	}
	if (data.nb_philo >= 2)
	{
		p = ft_init_philo(&data, &philo);
		if (!p)
			free(p);
		// ft_philo(&p);
		(void)p;
	}
	printf("fin main\n");
	return (0);
}
