/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/05/12 13:47:55 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int	nb_philo;
	int	timetodie;
	int	timetoeat;
	int	timetosleep;	
}	t_data;

typedef struct s_philo
{
	int				philo;
	//mutex;
	t_data			data;
	struct s_philo	**next;
}	t_philo;

typedef struct s_table
{
	int		philo_eat;
	// mutex; 2? imprime et manger
	t_data	*data;
}	t_table;

// main.c
int		main(int ac, char **av);
// utilis.c
void	ft_putstr_error(char *s, int fd);

#endif