/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/09/18 14:23:14 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

t_data	*data(void);
long	ft_atoi(char *str);
void	clean_mallocs(void);
long	get_time_stamp(void);
void	log_action(int id, char *action);

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

long	ft_atoi(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-' || !(str[i] >= '0' && str[i] <= '9'))
		{
			ft_printf(ARG_ERROR);
			exit (0);
		}
		nb = (nb * 10) + (str[i++] - 48);
	}
	return (nb);
}

void	clean_mallocs(void)
{
	int	i;
	int	n_philos;

	i = -1;
	n_philos = data()->n_philos;
	while (++i < n_philos)
		pthread_join(data()->philos[i].thread, NULL);
	i = -1;
	while (++i < n_philos)
		pthread_mutex_destroy(&(data()->forks[i]));
	pthread_mutex_destroy(&data()->use_print);
	pthread_mutex_destroy(&data()->use_data);
	free(data()->forks);
	free(data()->philos);
}

long	get_time_stamp(void)
{
	struct timeval	val;

	gettimeofday(&val, 0);
	return (val.tv_sec * 1000000L + val.tv_usec);
}

void	log_action(int id, char *action)
{
	pthread_mutex_lock(&(data()->use_print));
	if (philo_die(&(data()->philos[id])))
	{
		pthread_mutex_unlock(&(data()->use_print));
		return ;
	}
	ft_printf("%d\t%i\t%s\n", ((get_time_stamp() - data()->start_time) / 1000),
		id + 1, action);
	pthread_mutex_unlock(&(data()->use_print));
}
