/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/05/04 15:44:37 by anlima           ###   ########.fr       */
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
			philo_data()->number_of_philosophers = ft_atoi(argv[1]);
			philo_data()->time_to_die = ft_atoi(argv[2]);
			philo_data()->time_to_eat = ft_atoi(argv[3]);
			philo_data()->time_to_sleep = ft_atoi(argv[4]);
			if (argc == 6)
				philo_data()->ntimes_must_eat = ft_atoi(argv[5]);
			else
				philo_data()->ntimes_must_eat = -1;
			create_table();
			free(table()->philosophers);
		}
		else if (philos <= 0)
			write(1, ARG_FEW, 77);
	}
	else
		write(1, ARG_ERROR, 60);
	return (0);
}
