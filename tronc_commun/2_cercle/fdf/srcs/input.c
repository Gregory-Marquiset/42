/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:17:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 12:45:32 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_handle_cross(t_fdf *info)
{
	ft_free_and_out(info, 7, 1, "Success : cross as been pressed!\n");
	return (0);
}

void	ft_view_events(int keysym, t_fdf *info)
{
	if (keysym == XK_i)
	{
		info->modif.active_iso = 1;
		info->modif.active_para = 0;
	}
	else if (keysym == XK_p)
	{
		info->modif.active_iso = 0;
		info->modif.active_para = 1;
	}
	ft_draw_map(info);
}

void	ft_change_color(int color, t_fdf *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->map[y][x].c = color;
			x++;
		}
		y++;
	}
	info->modif.colors_modif = 1;
	ft_draw_map(info);
}

void	ft_colors_events(int keysym, t_fdf *info)
{
	if (keysym == XK_r)
		ft_change_color(C_RED, info);
	else if (keysym == XK_g)
		ft_change_color(C_GREEN, info);
	else if (keysym == XK_b)
		ft_change_color(C_BLUE, info);
	else if (keysym == XK_n)
	{
		int	y;
		int	x;

		y = 0;
		while (y < info->height)
		{
			x = 0;
			while (x < info->width)
			{
				info->map[y][x].c = info->map[y][x].c_ori;
				x++;
			}
			y++;
		}
		info->modif.colors_modif = 1;
		ft_draw_map(info);
	}
}

int	ft_handle_input(int keysym, t_fdf *info)
{
	if (keysym == XK_KP_Add || keysym == XK_KP_Subtract
		|| keysym == XK_KP_Multiply || keysym == XK_KP_Divide)
		ft_zoom_events(keysym, info);
	else if (keysym == XK_w || keysym == XK_d || keysym == XK_a
		|| keysym == XK_s)
		ft_move_events(keysym, info);
	else if (keysym == XK_KP_Up || keysym == XK_KP_Down || keysym == XK_KP_Left
		|| keysym == XK_KP_Right || keysym == XK_KP_Home
		|| keysym == XK_KP_Prior)
		ft_rotate_events(keysym, info);
	else if (keysym == XK_KP_Next || keysym == XK_KP_End || keysym == XK_KP_Begin)
		ft_z_events(keysym, info);
	else if (keysym == XK_space || keysym == XK_Escape)
		ft_reset_events(keysym, info);
	else if (keysym == XK_r || keysym == XK_g || keysym == XK_b
		|| keysym == XK_n)
		ft_colors_events(keysym, info);
	else if (keysym == XK_i || keysym == XK_p)
		ft_view_events(keysym, info);
	else if (keysym == XK_KP_Insert)
		ft_flat_event(info);
	else if (keysym == XK_KP_Delete)
		ft_hoist_event(info);
	ft_printf("%p\n", keysym);
	return (0);
}
/*
z event
0 XK_KP_Insert
. XK_KP_Delete
1 XK_KP_End
3 XK_KP_Next
5 XK_KP_Begin

rota
2 XK_KP_Down
4 XK_KP_Left
6 XK_KP_Right
7 XK_KP_Home
8 XK_KP_Up
9 XK_KP_Prior

zoom
+
-
*
/

reset
space

exit
escape

nouve
w
a
s
d

couleur
r
g
b
n

view
i
p
*/
