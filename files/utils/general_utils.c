/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/06/13 23:22:59 by anlima           ###   ########.fr       */
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
	if (str[i] == '+')
		i++;
	while (i < len)
	{
		if (str[i] == '+' || str[i] == '-' || (str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
		{
			ft_printf(ARG_ERROR);
			exit (0);
		}
		nb = (nb * 10) + (str[i++] - 48);
	}
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
	pthread_mutex_lock(&(data()->use_print));
	ft_printf("[%d ms]: Philosopher %i %s\n", (get_time_stamp() / 1000), id, action);
	pthread_mutex_unlock(&(data()->use_print));
}
