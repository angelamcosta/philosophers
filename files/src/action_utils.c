/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/06/20 15:14:41 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_die(t_philo philo);
void	philo_eat(t_philo philo);
void	philo_sleep(t_philo philo);
void	philo_think(t_philo philo);

void	philo_die(t_philo philo)
{
	pthread_mutex_lock(&(data()->use_data));
	if (!data()->philo_died)
	{
		data()->philo_died = 1;
		log_action(philo.id, "died");
	}
	pthread_mutex_unlock(&(data()->use_data));
}

void	philo_eat(t_philo philo)
{
	log_action(philo.id, "is eating");
	usleep(data()->eat);
	if (philo.ntimes_eat > 0)
		philo.ntimes_eat--;
	philo.last_meal = get_time_stamp();
	if (get_time_stamp() - philo.last_meal > data()->die)
		philo_die(philo);
}

void	philo_sleep(t_philo philo)
{
	log_action(philo.id, "is sleeping");
	usleep(data()->sleep);
	if (get_time_stamp() - philo.last_meal > data()->die)
		philo_die(philo);
}

void	philo_think(t_philo philo)
{
	log_action(philo.id, "is thinking");
	if (get_time_stamp() - philo.last_meal > data()->die)
		philo_die(philo);
}
