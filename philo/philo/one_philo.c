/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:54:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/26 18:29:59 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(int timetodie)
{
	long int	start;
	long int	status;
	long int	end;

	start = get_time();
	status = 0;
	if (start == -1)
		return (-1);
	end = start + timetodie;
	printf("0: Philo 1 is thinking\n");
	while (1 && status != -1)
	{
		status = get_time();
		if (status != -1 && status >= end)
			break ;
		ft_usleep(timetodie);
	}
	if (status == -1)
		return (-1);
	printf("%ld: Philo 1 has died\n", status - start);
	return (0);
}
