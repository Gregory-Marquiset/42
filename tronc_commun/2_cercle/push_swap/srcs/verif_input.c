/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:16:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/16 01:43:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_input_countain_double(char **clean_input)
{
	int	i;
	int	j;
	int	nbr1;
	int	nbr2;

	if (!clean_input || !clean_input[0])
		return (0);
	i = 0;
	while (clean_input[i])
	{
		j = 1;
		nbr1 = ft_atoi(clean_input[i]);
		while (clean_input[j])
		{
			nbr2 = ft_atoi(clean_input[j]);
			if (i != j && nbr1 == nbr2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_input_is_int(char *clean_input)
{
	long	nbr;

	if (!clean_input)
		return (0);
	nbr = ft_atol(clean_input);
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (1);
	else
		return (0);
}

static int	ft_input_is_digit(char *clean_input)
{
	int	i;

	if (!clean_input)
		return (0);
	i = 0;
	if (clean_input[i] == '-')
		i++;
	if (clean_input[i] == '\0')
		return (0);
	while (clean_input[i])
	{
		if (clean_input[i] > '9' || clean_input[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

char	**ft_check_input(char **input)
{
	int		i;
	char	*str;
	char	**clean_input;

	if (!input || !input[0])
		return (NULL);
	str = ft_join(input, ' ');
	clean_input = ft_split(str, ' ');
	free(str);
	i = 1;
	while (clean_input[i])
	{
		if (!ft_input_is_digit(clean_input[i]) || !ft_input_is_int(clean_input[i]))
			return (ft_le_xav(clean_input), NULL);
		i++;
	}
	if (ft_input_countain_double(clean_input))
		return (ft_le_xav(clean_input), NULL);
	return (clean_input);
}
/*
	verif de l'input:
		• Verifie que l'input ne contient que des nombres, int seulement,
			aucun doublons.
*/
