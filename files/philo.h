/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/05/10 14:15:02 by anlima           ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	int				die;
	int				eat;
	int				sleep;
	int				ntimes_eat;
	pthread_t		*thread;
	pthread_mutex_t	forks[2];
}				t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	*mutex;
}				t_fork;

typedef struct s_data
{
	int		number_of_philosophers;
	t_philo	**philosophers;
	t_fork	**forks;
}				t_data;

t_data	*data(void);
int		ft_atoi(char *str);
long	get_time_stamp(void);
void	log_action(char	*str);

#endif