/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/03/27 15:21:09 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 5 || argc == 6)
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
	else
		write(1, "Args error\n", 11);
	return (0);
}
