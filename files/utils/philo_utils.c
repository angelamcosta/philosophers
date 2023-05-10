/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:36 by anlima            #+#    #+#             */
/*   Updated: 2023/05/10 17:43:10 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_fork	*create_fork(int id);
t_philo	*create_philo(int id);
int	create_table(int die, int eat, int sleep, int ntimes_eat);

t_philo	*create_philo(int id)
{
	t_philo		*philo;
	
	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->id = id;
	philo->thread = NULL;
	return (philo);
}

t_fork	*create_fork(int id)
{
	t_fork			*fork;
	pthread_mutex_t	*mutex;
	
	fork = (t_fork *)malloc(sizeof(t_fork));
	if (!fork)
		return (0);
	fork->id = id;
	mutex  = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mutex)
	{
		free(fork);
		return (0);
	}
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		free(fork);
		return (0);
	}
	fork->mutex = mutex;
	return (fork);
}

int	create_table(int die, int eat, int sleep, int ntimes_eat)
{
	int	i;
	int	n_philo;

	n_philo = data()->number_of_philosophers;
	data()->philosophers = (t_philo **)malloc(sizeof(t_philo *) * n_philo);
	if (!data()->philosophers)
		return (0);
	if (n_philo == 1)
		data()->forks = (t_fork **)malloc(sizeof(t_fork *));
	else
		data()->forks = (t_fork **)malloc(sizeof(t_fork *) * n_philo - 1);
	if (!data()->forks)
	{
		free(data()->philosophers);
		return (0);
	}
	i = 0;
	while (i < n_philo)
	{
		data()->philosophers[i] = create_philo(i);
		if (i + 1 <= n_philo || n_philo == 1)
			data()->forks[i] = create_fork(i);
		i++;
	}
	return (1);
}

void	create_threads(void)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = data()->number_of_philosophers;
	while (i < n_philo)
	{
		pthread_create(&data()->philosophers[i], 0, &placeholder_fuction, 0);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		pthread_join(&data()->philosophers[i], 0);
		i++;
	}
}