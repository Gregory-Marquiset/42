/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_is_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 00:54:24 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/14 00:54:40 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_input_is_digit(char *input)
{
	int	i;

	if (!input)
		return (0);
	i = 0;
	if (input[i] == '-')
		i++;
	if (input[i] == '\0')
		return (0);
	while (input[i])
	{
		if (input[i] > '9' || input[i] < '0')
			return (0);
		i++;
	}
	return (1);
}
