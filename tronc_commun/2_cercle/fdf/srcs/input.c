/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:17:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 22:05:30 by gmarquis         ###   ########.fr       */
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
	int y;
	int x;

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
	else if(keysym == XK_g)
		ft_change_color(C_GREEN, info);
	else if (keysym == XK_b)
		ft_change_color(C_BLUE, info);
}

int	ft_handle_input(int keysym, t_fdf *info)
{
	if (keysym == XK_Escape)
		ft_free_and_out(info, 7, 1, "Success : ESC as been pressed\n");
	else if (keysym == XK_KP_Add || keysym == XK_KP_Subtract )
		ft_zoom_events(keysym, info);
	else if (keysym == XK_w || keysym == XK_d || keysym == XK_a || keysym == XK_s)
		ft_move_events(keysym, info);
	else if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym ==  XK_Right || keysym == XK_q || keysym == XK_e)
		ft_rotate_events(keysym, info);
	else if (keysym == XK_KP_Multiply || keysym == XK_KP_Divide)
		ft_z_events(keysym, info);
	else if (keysym == XK_space)
		ft_reset_events(info);
	else if (keysym == XK_r || keysym == XK_g || keysym == XK_b)
		ft_colors_events(keysym, info);
	else if (keysym == XK_i || keysym == XK_p)
		ft_view_events(keysym, info);
	return (0);
}
