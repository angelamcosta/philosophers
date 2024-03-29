/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:36:20 by anlima            #+#    #+#             */
/*   Updated: 2023/08/22 15:25:42 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_wait(void);
void	philo_eat(t_philo *philo);
int		philo_die(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

void	ft_wait(void)
{
	long	i;

	i = data()->start_time - get_time_stamp();
	if (i > 0)
		usleep(i);
}

void	philo_eat(t_philo *philo)
{
	log_action(philo->id, "is eating");
	philo->last_meal = get_time_stamp();
	usleep(data()->eat);
	if (philo->ntimes_eat > 0)
		philo->ntimes_eat--;
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
		pthread_mutex_unlock(&(data()->use_data));
		return (1);
	}
	pthread_mutex_unlock(&(data()->use_data));
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	if (philo->ntimes_eat == 0)
		return ;
	log_action(philo->id, "is sleeping");
	usleep(data()->sleep);
}

void	philo_think(t_philo *philo)
{
	long	i;

	if (philo->ntimes_eat == 0)
		return ;
	log_action(philo->id, "is thinking");
	i = data()->die - (get_time_stamp() - philo->last_meal)
		- (data()->eat / 2);
	if (i > 0)
		usleep(i);
}
