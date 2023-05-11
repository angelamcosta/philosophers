/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/05/11 17:09:45 by anlima           ###   ########.fr       */
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
			data()->num_of_philos = ft_atoi(argv[1]);
			create_table();
			if (argc == 6)
				fill_philo_info(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]), ft_atoi(argv[5]));
			else
				fill_philo_info(ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]), -1);
			create_threads();
		}
		else if (philos <= 0)
			ft_printf(ARG_FEW);
	}
	else
		ft_printf(ARG_ERROR);
	return (0);
}
