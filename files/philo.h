/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/03/28 14:48:36 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# define ARG_FEW "You need to have at leat 1 philosopher sitting at the table\n"
# define ARG_ERROR "You need at least 4 arguments\n"
# define RED "\033[91;1m"
# define GREEN "\033[92;1m"
# define YELLOW "\033[93;1m"
# define BLUE "\033[94;1m"
# define PINK "\033[95;1m"
# define CLEAR	"\033[0m"

typedef struct s_philo
{
	int				philo_number;
	int				left_fork;
	int				right_fork;
	pthread_t		pthread;
	struct s_philo	*next_philo;
}				t_philo;

typedef struct s_table
{
	int					nb_of_forks;
	int					nb_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					times_philo_must_eat;
	t_philo				*philos;
	int					time;
	pthread_mutex_t		p_mutex;
}				t_table;

t_table	*table(void);
int		ft_atoi(char *str);
t_philo	*lst_last(void);
void	populate_table(void);
t_philo	*create_philo(int philo_nb);
// int	p_eat();
// int	p_think();
// int	p_sleep();

#endif