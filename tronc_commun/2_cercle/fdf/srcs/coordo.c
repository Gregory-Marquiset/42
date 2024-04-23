/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:04:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 09:16:09 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_coordo_para(t_fdf *info, int y, int x)
{
	info->modif.tmp_x = x * info->modif.zoom + info->modif.dpl_x;
	info->modif.tmp_y = y * info->modif.zoom + info->modif.dpl_y;
	info->iso.rotated_y = info->modif.tmp_y * cos(info->modif.rotation_x)
		- info->map[y][x].z * sin(info->modif.rotation_x);
	info->iso.rotated_z = info->modif.tmp_y * sin(info->modif.rotation_x)
		+ info->map[y][x].z * cos(info->modif.rotation_x);
	info->iso.rotated_x = info->modif.tmp_x * cos(info->modif.rotation_y)
		+ info->iso.rotated_z * sin(info->modif.rotation_y);
	info->map[y][x].x = info->iso.rotated_x * cos(info->modif.rotation_z)
		- info->iso.rotated_y * sin(info->modif.rotation_z);
	info->map[y][x].y = info->iso.rotated_x * sin(info->modif.rotation_z)
		+ info->iso.rotated_y * cos(info->modif.rotation_z);
	info->map[y][x].x += (info->w_width - info->width * info->modif.zoom) / 2;
	info->map[y][x].y += (info->w_height - info->height * info->modif.zoom) / 2;
}

void	ft_coordo_iso(t_fdf *info, int y, int x)
{
	info->modif.tmp_x = (x - y) * cos(30 * M_PI / 180) * info->modif.zoom
		+ info->modif.dpl_x;
	info->modif.tmp_y = -info->map[y][x].z + (x + y) * sin(30 * M_PI / 180)
		* info->modif.zoom + info->modif.dpl_y;


	info->iso.rotated_y = info->modif.tmp_y * cos(info->modif.rotation_x)
		- info->map[y][x].z * sin(info->modif.rotation_x);

	info->iso.rotated_z = info->modif.tmp_y * sin(info->modif.rotation_x)
		+ info->map[y][x].z * cos(info->modif.rotation_x);

	info->iso.rotated_x = info->modif.tmp_x * cos(info->modif.rotation_y)
		+ info->iso.rotated_z * sin(info->modif.rotation_y);


	info->map[y][x].x = info->iso.rotated_x * cos(info->modif.rotation_z)
		- info->iso.rotated_y * sin(info->modif.rotation_z);
	info->map[y][x].y = info->iso.rotated_x * sin(info->modif.rotation_z)
		+ info->iso.rotated_y * cos(info->modif.rotation_z);

	info->map[y][x].x += (info->w_width - info->width * info->modif.zoom) / 2;
	info->map[y][x].y += (info->w_height - info->height * info->modif.zoom) / 2;
}
