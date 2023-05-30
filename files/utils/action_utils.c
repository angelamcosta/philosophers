/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/05/30 18:22:20 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo *philo);
void	*philo_handler(void	*ptr);
void	get_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	*philo_handler(void	*ptr)
{
	t_philo *philo = (t_philo *) ptr;
	while (philo->ntimes_eat == -1 || philo->ntimes_eat > 0)
	{
		if (get_time_stamp() - philo->last_meal > philo->die)
		{
			log_action(philo->id, "died");
			return (NULL);
		}
		if (data()->num_of_philos == 1)
			philo_think(philo);
		else
			get_forks(philo);
		if (philo->ntimes_eat != -1)
			philo->ntimes_eat--;
		philo_sleep(philo);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	log_action(philo->id, "is eating");
	philo->last_meal = get_time_stamp();
	usleep(philo->eat);
}

void	philo_sleep(t_philo *philo)
{
	log_action(philo->id, "is sleeping");
	usleep(philo->sleep);
}

void	philo_think(t_philo *philo)
{
	log_action(philo->id, "is thinking");
	usleep(THINK);
}

void	get_forks(t_philo *philo)
{
	int	left_fork;
	int	right_fork;

	left_fork = philo->id;
	right_fork = (left_fork + 1) % data()->num_of_philos;
	while (1)
	{
		if (pthread_mutex_trylock(data()->forks[left_fork]) == 0)
		{
			if (pthread_mutex_trylock(data()->forks[right_fork]) == 0)
				break ;
			else
			{
				pthread_mutex_unlock(data()->forks[left_fork]);
				philo_think(philo);
			}
		}
		else
			philo_think(philo);
	}
	philo_eat(philo);
	pthread_mutex_unlock(data()->forks[right_fork]);
	pthread_mutex_unlock(data()->forks[philo->id]);
}
