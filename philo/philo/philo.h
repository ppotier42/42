/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/07 15:13:12 by ppotier          ###   ########.fr       */
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

typedef struct s_philo
{
	int				id_philo;
	long int		time_eat;
	unsigned int	nb_p_eat;
	int				finish;

	pthread_t		thread_id;
	pthread_mutex_t	l_f;
	pthread_mutex_t	*r_f;
	pthread_mutex_t	write;
	pthread_mutex_t	philo_finish;

	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int			nb_philo;
	long int	timetodie;
	long int	timetoeat;
	long int	timetosleep;
	int			nb_meal;
	t_philo		*p;
}	t_data;

// main.c
int			main(int ac, char **av);
// utilis.c
void		ft_putstr_error(char *s, int fd);
long int	get_time(void);
int			ft_strlen(char *s);
int			ft_usleep(useconds_t time);
// check_args.c
t_data		*ft_check_args(int ac, char **av);
// one_philo.c
int			one_philo(int timetodie);

#endif