/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/03/27 15:34:15 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	int	philos;

	philos = ft_atoi(argv[1]);
	if ((argc == 5 || argc == 6) && philos > 0)
	{
		table()->nb_of_philo = ft_atoi(argv[1]);
		table()->nb_of_forks = table()->nb_of_philo;
		table()->time_to_die = ft_atoi(argv[2]);
		table()->time_to_eat = ft_atoi(argv[3]);
		table()->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table()->times_philo_must_eat = ft_atoi(argv[5]);
		else
			table()->times_philo_must_eat = -1;
		populate_table();
	}
	else if (argc < 5)
		write(1, ARG_ERROR, 30);
	else if (philos <= 0)
		write(1, ARG_FEW, 60);
	return (0);
}
