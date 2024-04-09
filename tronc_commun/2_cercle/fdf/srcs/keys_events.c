/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:24:27 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/09 02:27:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move_events(int keysym, t_fdf *info)
{
	if (keysym == XK_w)
		info->iso.dpl_y -= FACTOR;
	else if (keysym == XK_s)
		info->iso.dpl_y += FACTOR;
	else if (keysym == XK_d)
		info->iso.dpl_x += FACTOR;
	else if (keysym == XK_a)
		info->iso.dpl_x -= FACTOR;
	ft_draw_map(info);
}

void	ft_zoom_events(int keysym, t_fdf *info)
{
	double center_x;
	double center_y;

	center_x = WINDOW_WIDTH / 2;
	center_y = WINDOW_HEIGHT / 2;
	if (keysym == XK_KP_Add)
	{
		info->zoom *= 1.1;
		info->iso.iso_x = (info->iso.iso_x - center_x) * 1.1 + center_x;
		info->iso.iso_y = (info->iso.iso_y - center_y) * 1.1 + center_y;
	}
	else if (keysym == XK_KP_Subtract)
	{
		info->zoom /= 1.1;
		info->iso.iso_x = (info->iso.iso_x - center_x) / 1.1 + center_x;
		info->iso.iso_y = (info->iso.iso_y - center_y) / 1.1 + center_y;
	}
	ft_draw_map(info);
}

void ft_rotate_events(int keysym, t_fdf *info)
{
	double angle;

	angle = M_PI / 18;
	if (keysym == XK_Up)
		info->iso.rotation_x += angle;
	else if (keysym == XK_Down)
		info->iso.rotation_x += -angle;
	else if (keysym == XK_Left)
		info->iso.rotation_y += angle;
	else if (keysym == XK_Right)
		info->iso.rotation_y += -angle;
	else if (keysym == XK_q)
		info->iso.rotation_z += angle;
	else if (keysym == XK_e)
		info->iso.rotation_z += -angle;
	ft_draw_map(info);
}

void	ft_z_events(int keysym, t_fdf *info)
{
	int y;
	int x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->map[y][x].z_ori != 0)
			{
				if (keysym == XK_KP_Multiply)
					info->map[y][x].z += 1;
				else if (keysym == XK_KP_Divide)
					info->map[y][x].z -= 1;
			}
			x++;
		}
		y++;
	}
	ft_draw_map(info);
}

void	ft_reset_events(t_fdf *info)
{
	int y;
	int x;

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
	ft_init_iso(info);
	ft_draw_map(info);
}
