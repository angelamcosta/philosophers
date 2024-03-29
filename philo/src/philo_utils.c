/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:36 by anlima            #+#    #+#             */
/*   Updated: 2023/08/22 15:20:01 by anlima           ###   ########.fr       */
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
	data()->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
		* n_philos);
	pthread_mutex_init(&data()->use_print, 0);
	pthread_mutex_init(&data()->use_data, 0);
	create_philos();
}

void	create_philos(void)
{
	int	i;
	int	j;
	int	n_philos;

	i = -1;
	j = -1;
	n_philos = data()->n_philos;
	while (++i < n_philos)
	{
		while (++j < n_philos)
			pthread_mutex_init(&data()->forks[i], 0);
		data()->philos[i].id = i;
		data()->philos[i].n_philos = n_philos;
		data()->philos[i].ntimes_eat = data()->ntimes_eat;
		data()->philos[i].last_meal = get_time_stamp();
	}
	i = -1;
	while (++i < n_philos)
	{
		pthread_create(&(data()->philos[i].thread), 0, &philo_handler,
			(void *)&data()->philos[i]);
	}
	verify_deaths();
}

void	get_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id;
	right_fork = (left_fork + 1) % philo->n_philos;
	lock_forks(philo, left_fork, right_fork);
	philo_eat(philo);
	pthread_mutex_unlock(&data()->forks[right_fork]);
	pthread_mutex_unlock(&data()->forks[left_fork]);
	philo_sleep(philo);
	philo_think(philo);
}

void	*philo_handler(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	ft_wait();
	if (data()->n_philos == 1)
		philo_think(philo);
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!philo_die(philo))
	{
		if (philo->ntimes_eat == 0)
			break ;
		else if (philo->n_philos > 1)
			get_forks(philo);
	}
	return (0);
}

void	lock_forks(t_philo *philo, int left_fork, int right_fork)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&data()->forks[left_fork]);
		log_action(philo->id, "has taken a fork");
		pthread_mutex_lock(&data()->forks[right_fork]);
		log_action(philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&data()->forks[right_fork]);
		log_action(philo->id, "has taken a fork");
		pthread_mutex_lock(&data()->forks[left_fork]);
		log_action(philo->id, "has taken a fork");
	}
}
