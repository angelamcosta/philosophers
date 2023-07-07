/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:36 by anlima            #+#    #+#             */
/*   Updated: 2023/07/01 23:37:19 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	create_table(void);
void	create_philos(void);
void	get_forks(t_philo *philo);
void	*philo_handler(void *ptr);
void	lock_forks(t_philo *philo, int left_fork, int right_fork);

void	create_table(void)
{
	int	n_philos;

	n_philos = data()->n_philos;
	data()->philos = (t_philo *)malloc(sizeof(t_philo) * n_philos);
	data()->forks = (t_fork *)malloc(sizeof(t_fork) * n_philos);
	pthread_mutex_init(&data()->use_print, 0);
	pthread_mutex_init(&data()->use_data, 0);
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
		pthread_mutex_init(&data()->forks[i].fork, NULL);
		data()->forks[i].is_locked = 0;
		data()->philos[i].id = i;
		data()->philos[i].is_thinking = 0;
		data()->philos[i].ntimes_eat = data()->ntimes_eat;
		data()->philos[i].last_meal = get_time_stamp();
		pthread_create(&(data()->philos[i].thread), NULL, &philo_handler,
			(void *)&data()->philos[i]);
	}
}

void	get_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	if (philo->id % 2 == 0)
	{
		left_fork = philo->id;
		right_fork = (left_fork + 1) % data()->n_philos;
	}
	else
	{
		right_fork = philo->id;
		left_fork = (right_fork + 1) % data()->n_philos;
	}
	lock_forks(philo, left_fork, right_fork);
	philo_eat(philo);
	philo_think(philo);
	philo_sleep(philo);
	philo_think(philo);
}

void	*philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (philo->ntimes_eat != 0)
	{
		if (philo_die(philo))
			break ;
		if (data()->n_philos == 1)
			philo_think(philo);
		else
			get_forks(philo);
	}
	return (0);
}

void	lock_forks(t_philo *philo, int left_fork, int right_fork)
{
	while (!philo_die(philo))
	{
		pthread_mutex_lock(&data()->forks[left_fork].fork);
		if (!data()->forks[left_fork].is_locked)
		{
			data()->forks[left_fork].is_locked = 1;
			pthread_mutex_unlock(&data()->forks[left_fork].fork);
			break ;
		}
		philo_think(philo);
		pthread_mutex_unlock(&data()->forks[left_fork].fork);
	}
	log_action(philo->id, "has taken a fork");
	while (!philo_die(philo))
	{
		pthread_mutex_lock(&data()->forks[right_fork].fork);
		if (!data()->forks[right_fork].is_locked)
		{
			data()->forks[right_fork].is_locked = 1;
			pthread_mutex_unlock(&data()->forks[right_fork].fork);
			break ;
		}
		philo_think(philo);
		pthread_mutex_unlock(&data()->forks[right_fork].fork);
	}
	log_action(philo->id, "has taken a fork");
}
