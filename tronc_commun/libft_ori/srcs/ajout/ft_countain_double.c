/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countain_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:48:45 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/14 00:50:45 by gmarquis         ###   ########.fr       */
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
		while (input[j] && ft_input_is_digit(input[j]))
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
