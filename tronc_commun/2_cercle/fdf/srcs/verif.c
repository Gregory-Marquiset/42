/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 16:30:14 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_verif_cordo(char *str)
{
	long	nbr;

	if (!str)
		return (0);
	nbr = ft_atol(str);
	if (ft_isint(str))
		return ((int)nbr);
	return (0);
}
