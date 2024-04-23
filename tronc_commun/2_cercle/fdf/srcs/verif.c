/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/22 23:31:11 by gmarquis         ###   ########.fr       */
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

void	ft_verif_h(t_fdf *info)
{
	info->w_width = WINDOW_WIDTH;
	info->w_height = WINDOW_HEIGHT;
	info->factor = FACTOR;
	if (info->w_width < 500)
		info->w_width = 500;
	else if (info->w_width > 1920)
		info->w_width = 1920;
	if (info->w_height < 500)
		info->w_height = 500;
	else if (info->w_width > 1080)
		info->w_height = 1080;
	if (info->factor != 10)
		info->factor = 10;
}
