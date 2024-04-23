/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countuntil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 07:05:17 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 07:48:30 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_countuntil(char *str, char n)
{
	size_t	i;

	if (!str || !n)
		return (0);
	i = 0;
	while (str[i] && str[i] != n)
		i++;
	return (i);
}
