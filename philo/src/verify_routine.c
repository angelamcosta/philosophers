/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 15:06:50 by anlima            #+#    #+#             */
/*   Updated: 2023/08/22 15:24:21 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	verify_deaths(void);

void	verify_deaths(void)
{
	int	i;
	int	n_philos;

	ft_wait();
	i = -1;
	n_philos = data()->n_philos;
	while (1)
	{
		while (++i < n_philos)
		{
			if (philo_die(&data()->philos[i])
				|| data()->philos->ntimes_eat == 0)
				return ;
		}
		i = -1;
	}
}
