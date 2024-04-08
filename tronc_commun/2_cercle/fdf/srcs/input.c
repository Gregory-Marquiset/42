/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:17:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 10:24:22 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_handle_input(int keysym, t_fdf *info)
{
	if (keysym == MAIN_PAD_A || keysym == MAIN_PAD_D
		|| keysym == MAIN_PAD_S || keysym == MAIN_PAD_W)
		ft_rotate_event(keysym, info);

	else if (keysym == NUM_PAD_PLUS || keysym == NUM_PAD_MINUS || keysym == NUM_PAD_MULT || keysym == NUM_PAD_DIVIDE)
		ft_zoom_event(keysym, info);

	else if (keysym >= ARROW_LEFT && keysym <= ARROW_DOWN)
		ft_arrow_event(keysym, info);

	else if (keysym == MAIN_PAD_ESC)
		ft_free_and_out(info, 7, 1, "Success : ESC as been pressed\n");

	ft_printf("%d\n", keysym);

	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
		0);
	return (0);
}
