/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:33:18 by anlima            #+#    #+#             */
/*   Updated: 2023/03/27 15:13:37 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*lst_last(void);
void	populate_table(void);
t_philo	*create_philo(int philo_nb);

t_philo	*lst_last(void)
{
	t_philo	*temp;

	temp = table()->philos;
	if (!temp)
		return (NULL);
	while (temp->next_philo)
		temp = temp->next_philo;
	return (temp);
}

void	populate_table(void)
{
	int		i;
	t_philo	*aux;

	i = 1;
	while (i <= table()->nb_of_philo)
	{
		aux = lst_last();
		if (!aux)
			table()->philos = create_philo(i);
		else
			aux->next_philo = create_philo(i);
		i++;
	}
}

t_philo	*create_philo(int philo_nb)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->philo_number = philo_nb;
	philo->right_fork = 0;
	philo->left_fork = 0;
	philo->next_philo = NULL;
	return (philo);
}

// int	eat()
// {
// }

// int	think()
// {	
// }

// int	sleep()
// {	
// }