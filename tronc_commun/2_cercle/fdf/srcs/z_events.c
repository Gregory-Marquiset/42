/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_events.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:17:24 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/19 01:25:08 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_flat_event(t_fdf *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x].z_ori != 0)
			{
				if (info->map[y][x].z_ori > 0 && info->map[y][x].z > 0)
					info->map[y][x].z -= 1;
				else if (info->map[y][x].z_ori < 0 && info->map[y][x].z < 0)
					info->map[y][x].z += 1;
			}
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}

void	ft_hoist_event(t_fdf *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x].z_ori != 0)
			{
				if (info->map[y][x].z_ori > 0 && info->map[y][x].z > 0)
					info->map[y][x].z += 1;
				else if (info->map[y][x].z_ori < 0 && info->map[y][x].z < 0)
					info->map[y][x].z -= 1;
			}
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}

void	ft_z_revert(t_fdf *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x].z_ori != 0)
			{
				if (info->map[y][x].z_ori > 0)
					info->map[y][x].z -= 1;
				else if (info->map[y][x].z_ori < 0)
					info->map[y][x].z += 1;
			}
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}

void	ft_z_events(int keysym, t_fdf *info)
{
	int	y;
	int	x;

	if (keysym == XK_KP_Begin)
		ft_z_revert(info);
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x].z_ori != 0)
			{
				if (keysym == XK_KP_End && info->map[y][x].z_ori > 0)
					info->map[y][x].z += 1;
				else if (keysym == XK_KP_Next && info->map[y][x].z_ori < 0)
					info->map[y][x].z -= 1;
			}
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}
