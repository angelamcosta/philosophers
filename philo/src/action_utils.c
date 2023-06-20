/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/06/20 17:55:58 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	philo_eat(t_philo philo);
void	philo_sleep(t_philo philo);
void	philo_think(t_philo philo);

void	philo_eat(t_philo philo)
{
	log_action(philo.id, "is eating");
	philo.last_meal = get_time_stamp();
	usleep(data()->eat);
	if (philo.ntimes_eat > 0)
		philo.ntimes_eat--;
	if (get_time_stamp() - philo.last_meal >= data()->die)
	{
		log_action(philo.id, "died");
		clean_mallocs();
		exit(0);
	}
}

void	philo_sleep(t_philo philo)
{
	log_action(philo.id, "is sleeping");
	usleep(data()->sleep);
	if (get_time_stamp() - philo.last_meal >= data()->die)
	{
		log_action(philo.id, "died");
		clean_mallocs();
		exit(0);
	}
}

void	philo_think(t_philo philo)
{
	log_action(philo.id, "is thinking");
	if (get_time_stamp() - philo.last_meal >= data()->die)
	{
		log_action(philo.id, "died");
		clean_mallocs();
		exit(0);
	}
}
