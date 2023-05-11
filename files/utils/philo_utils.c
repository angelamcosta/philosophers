/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:22:36 by anlima            #+#    #+#             */
/*   Updated: 2023/05/11 17:17:44 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int				create_table(void);
void			create_threads(void);
pthread_mutex_t	*create_fork(void);
t_philo			*create_philo(int id);
void			fill_philo_info(int die, int eat, int sleep, int ntimes_eat);

t_philo	*create_philo(int id)
{
	t_philo		*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->id = id;
	philo->thread = malloc(sizeof(pthread_t));
	if (!philo->thread)
	{
		free(philo);
		return (0);
	}
	return (philo);
}

pthread_mutex_t	*create_fork(void)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!mutex)
		return (0);
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		free(mutex);
		return (0);
	}
	return (mutex);
}

int	create_table(void)
{
	int	i;
	int	n_philo;

	n_philo = data()->num_of_philos;
	data()->philosophers = (t_philo **)malloc(sizeof(t_philo *) * n_philo);
	if (!data()->philosophers)
		return (0);
	if (n_philo == 1)
		data()->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *));
	else
		data()->forks = (pthread_mutex_t **)malloc(sizeof(pthread_mutex_t *) * n_philo - 1);
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
			data()->forks[i] = create_fork();
		i++;
	}
	return (1);
}

void	create_threads(void)
{
	int	i;
	int	n_philo;

	i = -1;
	n_philo = data()->num_of_philos;
	while (++i < n_philo)
		pthread_create(data()->philosophers[i]->thread, 0, &philo_handler, (void *)data()->philosophers[i]);
	i = -1;
	while (++i < n_philo)
	{
		if (pthread_join(*(data()->philosophers[i]->thread), 0) != 0)
		{
			log_action(data()->philosophers[i]->id, "died");
			return ;
		}
	}
}

void	fill_philo_info(int die, int eat, int sleep, int ntimes_eat)
{
	int	i;
	int	n_philo;

	i = 0;
	n_philo = data()->num_of_philos;
	while (i < n_philo)
	{
		data()->philosophers[i]->die = die * 1000;
		data()->philosophers[i]->eat = eat * 1000;
		data()->philosophers[i]->sleep = sleep * 1000;
		data()->philosophers[i]->ntimes_eat = ntimes_eat;
		data()->philosophers[i]->last_meal = get_time_stamp();
		i++;
	}
}
