/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/05/09 15:47:26 by anlima           ###   ########.fr       */
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

typedef struct s_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	ntimes_must_eat;
}				t_data;

t_data	*data(void);
int		ft_atoi(char *str);
long	get_time_stamp(void);
void	log_action(char	*str);

#endif