/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:14:00 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/15 08:14:28 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long	ft_atol(char *input)
{
	int		i;
	int		sign;
	long	rslt;

	i = 0;
	sign = 1;
	rslt = 0;
	if (input[i] == '+')
		i++;
	else if (input[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (ft_isdigit(input[i]))
	{
		rslt = (rslt * 10) + input[i] - 48;
		i++;
	}
	return (rslt * sign);
}
