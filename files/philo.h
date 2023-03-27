/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/03/27 15:33:25 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# define ARG_FEW "You need to have at leat 1 philosopher sitting at the table\n"
# define ARG_ERROR "You need at least 4 arguments\n"

typedef struct s_philo
{
	int				philo_number;
	int				left_fork;
	int				right_fork;
	struct s_philo	*next_philo;
}				t_philo;

typedef struct s_table
{
	int		nb_of_forks;
	int		nb_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		times_philo_must_eat;
	t_philo	*philos;
}				t_table;

t_table	*table(void);
int		ft_atoi(char *str);
t_philo	*lst_last(void);
void	populate_table(void);
t_philo	*create_philo(int philo_nb);
// int	eat();
// int	think();
// int	sleep();

#endif