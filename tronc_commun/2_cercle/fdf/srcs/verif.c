/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:01:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 11:01:09 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_verif_in_window(t_fdf *info, int y, int x)
{
	if (info->map[y][x].x < 0 || info->map[y][x].x >= WINDOW_WIDTH)
	{
		if (info->map[y][x].x < 0)
			info->map[y][x].x = 1;
		if (info->map[y][x].x >= WINDOW_WIDTH)
			info->map[y][x].x = WINDOW_WIDTH - 1;
		if (info->map[y][x].x == 1 && info->map[y][x].x < MENU_WIDTH)
			info->map[y][x].c = MENU_BACKGROUND;
	}
	else if (info->map[y][x].y < 0 || info->map[y][x].y >= WINDOW_HEIGHT)
	{
		if (info->map[y][x].y < 0)
			info->map[y][x].y = 1;
		if (info->map[y][x].y >= WINDOW_HEIGHT)
			info->map[y][x].y = WINDOW_HEIGHT - 1;
		if ((info->map[y][x].y == 1 || info->map[y][x].y == WINDOW_HEIGHT - 1)
			&& info->map[y][x].x < MENU_WIDTH)
			info->map[y][x].c = MENU_BACKGROUND;
	}
	ft_get_color_modif(info, y, x);
}

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
