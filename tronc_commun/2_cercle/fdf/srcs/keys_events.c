/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:24:27 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/17 06:22:55 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_z(int keysym, t_fdf *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (keysym == XK_q)
				info->map[y][x].z += FACTOR / 2;
			if (keysym == XK_e)
				info->map[y][x].z -= FACTOR / 2;
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}

void	ft_move_events(int keysym, t_fdf *info)
{
	if (keysym == XK_w)
		info->modif.dpl_y -= FACTOR;
	else if (keysym == XK_s)
		info->modif.dpl_y += FACTOR;
	else if (keysym == XK_d)
		info->modif.dpl_x += FACTOR;
	else if (keysym == XK_a)
		info->modif.dpl_x -= FACTOR;
	else if (keysym == XK_q || keysym == XK_e)
		ft_move_z(keysym, info);
	ft_draw_map(info);
}

void	ft_zoom_events(int keysym, t_fdf *info)
{
	if (keysym == XK_KP_Add)
		info->modif.zoom *= 1.1;
	else if (keysym == XK_KP_Multiply)
		info->modif.zoom *= 2.0;
	else if (keysym == XK_KP_Subtract)
		info->modif.zoom /= 1.1;
	else if (keysym == XK_KP_Divide)
		info->modif.zoom /= 2.0;

	if ((info->height < 50 || info->width < 50) && info->modif.zoom > 50)
		info->modif.zoom = 50;
	if ((info->height < 50 || info->width < 50) && info->modif.zoom < 10)
		info->modif.zoom = 10;

	if ((info->height > 50 || info->width > 50) && info->modif.zoom > 8)
		info->modif.zoom = 8;
	if ((info->height > 50 || info->width > 50) && info->modif.zoom < 1)
		info->modif.zoom = 1;

	if ((info->height > 100 || info->width > 100) && info->modif.zoom > 4)
		info->modif.zoom = 4;
	if ((info->height > 100 || info->width > 100) && info->modif.zoom < 1)
		info->modif.zoom = 1;

	if ((info->height > 200 || info->width > 200) && info->modif.zoom > 1.5)
		info->modif.zoom = 1.5;
	if ((info->height > 200 || info->width > 200) && info->modif.zoom < 1)
		info->modif.zoom = 1;
	ft_draw_map(info);
}

void	ft_rotate_events(int keysym, t_fdf *info)
{
	double	angle;

	angle = M_PI / 18;
	if (keysym == XK_KP_Up)
		info->modif.rotation_x += angle;
	else if (keysym == XK_KP_Down)
		info->modif.rotation_x += -angle;
	else if (keysym == XK_KP_Left)
		info->modif.rotation_y += angle;
	else if (keysym == XK_KP_Right)
		info->modif.rotation_y += -angle;
	else if (keysym == XK_KP_Home)
		info->modif.rotation_z += angle;
	else if (keysym == XK_KP_Prior)
		info->modif.rotation_z += -angle;
	ft_draw_map(info);
}

void	ft_reset_events(int keysym, t_fdf *info)
{
	int	y;
	int	x;

	if (keysym == XK_Escape)
		ft_free_and_out(info, 7, 1, "Success : ESC as been pressed\n");
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->map[y][x].x = info->map[y][x].x_ori;
			info->map[y][x].y = info->map[y][x].y_ori;
			info->map[y][x].z = info->map[y][x].z_ori;
			x++;
		}
		y++;
	}
	ft_init_modif_view(info);
	ft_draw_map(info);
}
