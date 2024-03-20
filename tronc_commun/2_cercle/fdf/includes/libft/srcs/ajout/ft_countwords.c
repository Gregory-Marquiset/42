/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:57:10 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 17:13:05 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_countwords(char *str, char set, char set2, char end)
{
	int	i;
	int	check;
	int	countw;

	i = 0;
	check = 1;
	countw = 0;
	while (str[i] != end)
	{
		if (str[i] == set || str[i] == set2)
			check = 1;
		else if (check == 1)
		{
			countw++;
			check = 0;
		}
		i++;
	}
	return (countw);
}
