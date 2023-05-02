/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/02 13:21:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(int ac, char **av)
{
	int	nb_philo;
	int	time_to_die;

	nb_philo = ft_atoi(av[1]);
	
}

int	main(int ac, char **av)
{
	if (ac == 5)
		ft_init_philo(ac, av);
	else if (ac == 6)
		ft_init_philo(ac, av);
	return (0);
}