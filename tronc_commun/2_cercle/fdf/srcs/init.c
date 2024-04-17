/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/17 07:20:57 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_drawl(t_fdf *info, int y, int x, int flag)
{
	if (flag == 0)
	{
		info->drawl.x0 = info->map[y][x - 1].x;
		info->drawl.y0 = info->map[y][x - 1].y;
		info->drawl.x1 = info->map[y][x].x;
		info->drawl.y1 = info->map[y][x].y;
		info->drawl.c_start = info->map[y][x].c;
		info->drawl.c_end = info->map[y][x - 1].c;
	}
	else
	{
		info->drawl.x0 = info->map[y - 1][x].x;
		info->drawl.y0 = info->map[y - 1][x].y;
		info->drawl.x1 = info->map[y][x].x;
		info->drawl.y1 = info->map[y][x].y;
		info->drawl.c_start = info->map[y][x].c;
		info->drawl.c_end = info->map[y - 1][x].c;
	}
	info->drawl.delta_x = abs(info->drawl.x1 - info->drawl.x0);
	info->drawl.delta_y = abs(info->drawl.y1 - info->drawl.y0);
	info->drawl.step_y = 1;
	info->drawl.step_x = 1;
	info->drawl.error = info->drawl.delta_x - info->drawl.delta_y;
	info->drawl.error2 = 0;
	info->modif.dpl_z = 0;
}

void	ft_init_modif_view(t_fdf *info)
{
	ft_get_zoom(info);
	info->modif.colors_modif = 0;
	info->modif.active_iso = 1;
	info->modif.active_para = 0;
	info->modif.dpl_x = 0;
	info->modif.dpl_y = 0;
	info->modif.dpl_z = 0;
	info->modif.tmp_x = 0;
	info->modif.tmp_y = 0;
	info->modif.tmp_z = 0;
	info->modif.rotation_x = 0;
	info->modif.rotation_y = 0;
	info->modif.rotation_z = 0;
	info->iso.rotated_y = 0;
	info->iso.rotated_z = 0;
	info->iso.rotated_x = 0;
}

void	ft_init_window(t_fdf *info)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		ft_free_and_out(info, 5, 2,
			"Error: Unable to initialize connection with graphics server.\n");
	info->win_ptr = mlx_new_window(info->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (info->win_ptr == NULL)
		ft_free_and_out(info, 6, 2, "Error: window not initialized.\n");
	ft_init_modif_view(info);
}

t_point	ft_init_point(int x, int y, char *str)
{
	t_point	new;

	new.x = x;
	new.y = y;
	new.x_ori = x;
	new.y_ori = y;
	new.z = ft_verif_cordo(str);
	new.c = ft_get_color(str);
	new.z_ori = new.z;
	new.c_ori = new.c;
	new.v = 1;
	return (new);
}

void	ft_init_fdf(t_fdf *info)
{
	info->height = ft_countwords(info->one_line, '\n', '\n', '\0');
	info->width = ft_countwords(info->one_line, ' ', ' ', '\n');
	info->map_2d = ft_split(info->one_line, ' ', '\n');
	if (!info->map_2d)
		ft_free_and_out(info, 1, 2, "Error: failed creation of map_2d.\n");
	ft_get_map(info);
}
