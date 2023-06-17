/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:50:24 by anlima            #+#    #+#             */
/*   Updated: 2023/06/17 22:42:54 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (argc >= 5 && argc <= 6)
	{
		data()->n_philos = ft_atoi(argv[1]);
		if (data()->n_philos <= 0)
			return (ft_printf(ARG_FEW));
		data()->die = ft_atoi(argv[2]) * 1000;
		data()->eat = ft_atoi(argv[3]) * 1000;
		data()->sleep = ft_atoi(argv[4]) * 1000;
		if (argc == 6)
			data()->ntimes_eat = ft_atoi(argv[5]);
		else
			data()->ntimes_eat = -1;
		create_table();
	}
	else
		ft_printf(ARG_ERROR);
	clean_mallocs();
	return (0);
}
