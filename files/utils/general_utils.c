/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/05/26 16:02:10 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_data			*data(void);
pthread_mutex_t	*print_lock(void);
int				ft_atoi(char *str);
long			get_time_stamp(void);
void			log_action(int id, char *action);

t_data	*data(void)
{
	static t_data	data;

	return (&data);
}

int	ft_atoi(char *str)
{
	int		i;
	long	nb;
	int		len;

	i = 0;
	nb = 0;
	len = 0;
	while (str && str[len])
		len++;
	if (str[i] == '-')
		i++;
	while (i < len)
		nb = (nb * 10) + (str[i++] - 48);
	if (str[0] == '-')
		nb *= -1;
	return (nb);
}

long	get_time_stamp(void)
{
	struct timeval	val;

	gettimeofday(&val, 0);
	return (val.tv_sec * 1000000L + val.tv_usec);
}

void	log_action(int id, char *action)
{
	pthread_mutex_lock(data()->use_print);
	ft_printf("[%d]: Philosopher %i %s\n", get_time_stamp(), id, action);
	pthread_mutex_unlock(data()->use_print);
}
