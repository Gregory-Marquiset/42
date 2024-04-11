/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:08:08 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 09:26:46 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isint(char *input)
{
	long	nbr;

	if (!input)
		return (0);
	nbr = ft_atol(input);
	if (nbr >= -2147483648 && nbr <= 2147483647)
		return (1);
	else
		return (0);
}
