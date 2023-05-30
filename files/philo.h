/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/05/30 18:25:02 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include "./print_utils/ft_printf.h"
# define ARG_ERROR "\033[91;1mYou need at least 4 and at max 5 arguments\033[0m\n"
# define ARG_FEW "\033[93;1mYou need to have at leat 1 philosopher sitting at the table\033[0m\n"
# define THINK 500000

typedef struct s_philo
{
	int				id;
	long			die;
	long			eat;
	long			sleep;
	int				ntimes_eat;
	long			last_meal;
	pthread_t		*thread;
}				t_philo;

typedef struct s_data
{
	int				num_of_philos;
	t_philo			**philosophers;
	pthread_mutex_t	**forks;
	pthread_mutex_t	use_print;
}				t_data;

void			philo_eat(t_philo *philo);
void			*philo_handler(void	*ptr);
void			get_forks(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			philo_think(t_philo *philo);
t_data			*data(void);
pthread_mutex_t	*print_lock(void);
int				ft_atoi(char *str);
long			get_time_stamp(void);
void			log_action(int id, char *action);
int				create_table(void);
void			create_threads(void);
pthread_mutex_t	*create_fork(void);
t_philo			*create_philo(int id);
void			fill_philo_info(int die, int eat, int sleep, int ntimes_eat);

#endif