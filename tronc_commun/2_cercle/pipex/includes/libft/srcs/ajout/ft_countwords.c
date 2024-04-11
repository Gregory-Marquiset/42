/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:57:10 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 22:21:12 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_countwords(char *str, char set, char set2, char end)
{
	int	i;
	int	check;
	int	countw;

	if (!str || !set || !set2 || str[0] == '\0')
		return (0);
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
