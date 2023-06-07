/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 17:54:44 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/05 16:42:04 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(int timetodie)
{
	printf("0: Philo 1 is thinking\n");
	ft_usleep(timetodie);
	printf("%d: Philo 1 died\n", timetodie);
	return (0);
}
