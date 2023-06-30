/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/07/01 00:48:36 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo *philo);
int		philo_die(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	philo_eat(t_philo *philo)
{
	if (philo_die(philo))
		return ;
	log_action(philo->id, "is eating");
	philo->last_meal = get_time_stamp();
	usleep(data()->eat);
	if (philo->ntimes_eat > 0)
		philo->ntimes_eat--;
	if (philo_die(philo))
		return ;
}

int	philo_die(t_philo *philo)
{
	pthread_mutex_lock(&(data()->use_data));
	if (data()->philo_died)
	{
		pthread_mutex_unlock(&(data()->use_data));
		return (1);
	}
	if (get_time_stamp() - philo->last_meal >= data()->die)
	{
		ft_printf("%d\t%i\t%s\n", ((get_time_stamp() - data()->start_time) / 1000),
			philo->id + 1, "died");
		data()->philo_died = 1;
	}
	pthread_mutex_unlock(&(data()->use_data));
	return (data()->philo_died);
}

void	philo_sleep(t_philo *philo)
{
	if (philo_die(philo))
		return ;
	log_action(philo->id, "is sleeping");
	usleep(data()->sleep);
	if (philo_die(philo))
		return ;
}

void	philo_think(t_philo *philo)
{
	if (philo_die(philo) || philo->ntimes_eat == 0)
		return ;
	log_action(philo->id, "is thinking");
	usleep(data()->n_philos * 250);
	if (philo_die(philo))
		return ;
}
