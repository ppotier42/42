/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:07:54 by ppotier           #+#    #+#             */
/*   Updated: 2023/06/15 14:47:10 by ppotier          ###   ########.fr       */
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
# include <limits.h>

typedef struct s_data	t_data;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				flag_fork;
}	t_fork;

typedef struct s_philo
{
	int				id_philo;
	int				eat_count;
	int				finish;
	// int				is_dead;
	long int		last_meal;

	pthread_t		thread;

	t_fork			*l_f;
	t_fork			*r_f;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	long int		timetodie;
	long int		timetoeat;
	long int		timetosleep;
	long int		start_time;
	int				nb_meal;
	int				is_dead;

	pthread_mutex_t	write;
	pthread_mutex_t	dead;
	t_fork			*forks;
	t_philo			*p;
}	t_data;

// main.c
int			main(int ac, char **av);
void		ft_stop(t_data *data, t_philo *philo);
// utilis.c
void		ft_putstr_error(char *s, int fd);
long int	get_time(void);
int			ft_strlen(char *s);
int			ft_usleep(useconds_t time, t_data *data, t_philo *philo);
int			is_dead(t_data *data, t_philo *philo);
// check_args.c
t_data		*ft_init_args(int ac, char **av);
// one_philo.c
int			one_philo(int timetodie);
void		write_status(char *s, t_philo *philo, t_data *data);
//	routine.c
void		write_status(char *s, t_philo *philo, t_data *data);
void		ft_eat_sleep_think(t_data *data, t_philo *philo);
void		*routine(void *arg);


#endif