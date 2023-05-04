/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:33:18 by anlima            #+#    #+#             */
/*   Updated: 2023/05/04 15:30:48 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*table(void);
int		create_table(void);
t_data	*philo_data(void);

t_table	*table(void)
{
	static t_table	table;

	return (&table);
}

int	create_table(void)
{
	int	n_philo;

	n_philo = philo_data()->number_of_philosophers;
	table()->philosophers = (pthread_t **)malloc(sizeof(pthread_t) + 1);
	if (!table()->philosophers)
		return (0);
	if (n_philo > 1)
		table()->number_of_forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t) - 1);
	else
		table()->number_of_forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t));
	return (1);
}

t_data	*philo_data(void)
{
	static t_data	data;

	return (&data);
}
