/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/08/22 15:17:35 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "./ft_printf.h"
# define ARG_ERROR "\033[91;1mYou need 4 or 5 valid positive arguments\033[0m\n"
# define ARG_FEW "\033[93;1mYou need at least 1 philo at the table\033[0m\n"

typedef struct s_philo
{
	int				id;
	int				n_philos;
	int				ntimes_eat;
	long			last_meal;
	pthread_t		thread;
}				t_philo;

typedef struct s_data
{
	int				n_philos;
	int				philo_died;
	int				ntimes_eat;
	long			die;
	long			eat;
	long			sleep;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	long			start_time;
	pthread_mutex_t	use_print;
	pthread_mutex_t	use_data;
}				t_data;

void	ft_wait(void);
int		philo_die(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
t_data	*data(void);
long	ft_atoi(char *str);
void	clean_mallocs(void);
long	get_time_stamp(void);
void	log_action(int id, char *action);
void	create_table(void);
void	create_philos(void);
void	get_forks(t_philo *philo);
void	*philo_handler(void *ptr);
void	lock_forks(t_philo *philo, int left_fork, int right_fork);
void	verify_deaths(void);

#endif