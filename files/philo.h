/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:26 by anlima            #+#    #+#             */
/*   Updated: 2023/03/25 17:07:49 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_table
{
	int	philosophers;
	int	forks;
}				t_table;

typedef struct s_philo
{
	int				philo_number;
	int				left_fork;
	int				right_fork;
	struct s_philo	*next_philo;
}				t_philo;

t_philo	*philos(void);
int		ft_atoi(char *str);
// int	eat();
// int	think();
// int	sleep();

#endif