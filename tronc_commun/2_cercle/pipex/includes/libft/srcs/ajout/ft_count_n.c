/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:34:49 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/17 18:37:51 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_count_n(char *str, char n)
{
	int	i;
	int	count;

	if (!str || !n)
		return (0);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == n)
			count++;
		i++;
	}
	return (count);
}
