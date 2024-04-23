/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countain_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:48:45 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 04:32:44 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_countain_double(char **input)
{
	int	i;
	int	j;
	int	nbr1;
	int	nbr2;

	if (!input || !input[0])
		return (0);
	i = 0;
	while (input[i])
	{
		j = 1;
		nbr1 = ft_atoi(input[i]);
		while (input[j] && ft_isnbr(input[j]))
		{
			nbr2 = ft_atoi(input[j]);
			if (i != j && nbr1 == nbr2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
