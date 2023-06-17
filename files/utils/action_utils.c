/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/06/17 23:35:58 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	philo_eat(t_philo philo);
void	philo_sleep(t_philo philo);
void	philo_think(t_philo philo);

void	philo_eat(t_philo philo)
{
	log_action(philo.id, "is eating");
	if (get_time_stamp() - (philo.last_meal + data()->eat) > data()->die)
		philo_die(philo);
	usleep(data()->eat);
	if (philo.ntimes_eat > 0)
		philo.ntimes_eat--;
	philo.last_meal = get_time_stamp();
}

void	philo_sleep(t_philo philo)
{
	log_action(philo.id, "is sleeping");
	if (get_time_stamp() - (philo.last_meal + data()->sleep) > data()->die)
		philo_die(philo);
	usleep(data()->sleep);
}

void	philo_think(t_philo philo)
{
	log_action(philo.id, "is thinking");
}
