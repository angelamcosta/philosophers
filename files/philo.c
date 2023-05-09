/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/05/09 15:50:59 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	philos;

	if (argc >= 5 && argc <= 6)
	{
		philos = ft_atoi(argv[1]);
		if ((argc == 5 || argc == 6) && philos > 0)
		{
			data()->number_of_philosophers = ft_atoi(argv[1]);
			data()->time_to_die = ft_atoi(argv[2]);
			data()->time_to_eat = ft_atoi(argv[3]);
			data()->time_to_sleep = ft_atoi(argv[4]);
			if (argc == 6)
				data()->ntimes_must_eat = ft_atoi(argv[5]);
			else
				data()->ntimes_must_eat = -1;
			log_action("Program has started");
		}
		else if (philos <= 0)
			ft_printf(ARG_FEW);
	}
	else
		ft_printf(ARG_ERROR);
	return (0);
}
