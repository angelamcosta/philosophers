/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/03/27 15:21:16 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_table	*table(void);
int		ft_atoi(char *str);

t_table	*table(void)
{
	static t_table	table;

	return (&table);
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
