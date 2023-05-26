/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:35 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/26 18:22:36 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		result;

	result = 0;
	if (!(ft_check_args(ac, av, &data)))
		return (ft_putstr_error("Invalid args", 2), 1);
	if (data.nb_philo == 1)
	{	
		printf("timetodie: %ld\n", data.timetodie);
		result = one_philo(data.timetodie);
		return (result);
	}
	return (0);
}