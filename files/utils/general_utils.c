/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:02:39 by anlima            #+#    #+#             */
/*   Updated: 2023/05/04 15:10:06 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int		ft_atoi(char *str);

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
