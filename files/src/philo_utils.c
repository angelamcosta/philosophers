/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:36 by anlima            #+#    #+#             */
/*   Updated: 2023/06/20 14:01:12 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_table(void);
void	create_philos(void);
void	get_forks(t_philo philo);
void	philo_die(t_philo philo);
void	*philo_handler(void *ptr);

void	create_table(void)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = data()->n_philos;
	data()->philos = (t_philo *)malloc(sizeof(t_philo) * n_philos);
	data()->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
		* n_philos);
	pthread_mutex_init(&data()->use_print, 0);
	while (++i < n_philos)
		pthread_mutex_init(&data()->forks[i], 0);
	create_philos();
}

void	create_philos(void)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = data()->n_philos;
	while (++i < n_philos)
	{
		data()->philos[i].id = i;
		data()->philos[i].ntimes_eat = data()->ntimes_eat;
		data()->philos[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		data()->philos[i].last_meal = get_time_stamp();
		pthread_create(data()->philos[i].thread, 0, &philo_handler,
			(void *)&data()->philos[i]);
	}
}

void	get_forks(t_philo philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo.id;
	right_fork = left_fork + 1 % data()->n_philos;
	while (1)
	{
		if (pthread_mutex_trylock(&data()->forks[left_fork]) == 0)
		{
			if (pthread_mutex_trylock(&data()->forks[right_fork]) == 0)
				break ;
			else
				philo_think(philo);
		}
		else
			philo_think(philo);
	}
	philo_eat(philo);
	pthread_mutex_unlock(&data()->forks[right_fork]);
	pthread_mutex_unlock(&data()->forks[left_fork]);
	philo_sleep(philo);
}

void	philo_die(t_philo philo)
{
	log_action(philo.id, "died");
	clean_mallocs();
	exit (0);
}

void	*philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (philo->ntimes_eat != 0)
	{
		if (get_time_stamp() - philo->last_meal > data()->die)
			philo_die(*philo);
		if (data()->n_philos == 1)
			philo_think(*philo);
		else
			get_forks(*philo);
	}
	return (0);
}
