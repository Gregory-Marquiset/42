/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:17:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 14:01:49 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_handle_cross(t_fdf *info)
{
	ft_free_and_out(info, 7, 1, "Success : cross as been pressed!\n");
	return (0);
}

void	ft_iso_view(t_fdf *info)
{
	info->iso.active = 1;
	ft_draw_map(info);
}

int	ft_handle_input(int keysym, t_fdf *info)
{
	if (keysym == XK_Escape)
		ft_free_and_out(info, 7, 1, "Success : ESC as been pressed\n");
	if (keysym == XK_KP_Add || keysym == XK_KP_Subtract )
		ft_zoom_events(keysym, info);
	if (keysym == XK_w || keysym == XK_d || keysym == XK_a || keysym == XK_s)
		ft_move_events(keysym, info);
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym ==  XK_Right || keysym == XK_q || keysym == XK_e)
		ft_rotate_events(keysym, info);
	if (keysym == XK_KP_Multiply || keysym == XK_KP_Divide)
		ft_z_events(keysym, info);
	if (keysym == XK_space)
		ft_reset_events(info);
	if (keysym == XK_i)
		ft_iso_view(info);
	return (0);
}
