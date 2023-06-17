/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/06/17 22:49:22 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data	*data(void);
int		ft_atoi(char *str);
void	clean_mallocs(void);
long	get_time_stamp(void);
void	log_action(int id, char *action);

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	ft_atoi(char *str)
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
	{
		free(data()->philos[i].thread);
		pthread_mutex_destroy(&(data()->forks[i]));
	}
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
	ft_printf("[%d: ms]: Philosopher %i %s\n", (get_time_stamp() / 1000),
		id, action);
	pthread_mutex_unlock(&(data()->use_print));
}
