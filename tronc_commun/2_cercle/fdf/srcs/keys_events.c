/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:24:27 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 12:33:00 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
