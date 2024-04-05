/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:17:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/05 09:21:28 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_fdf *info, int color)
{
	for (int y = 0; y < WINDOW_WIDTH; ++y)
		for (int x = 0; x < WINDOW_WIDTH; ++x)
			my_pixel_put(&info->img, x, y, color);
}
int	ft_handle_input(int keysym, t_fdf *info)
{
	if (keysym == XK_r)
		color_screen(info, 0xff0000);
	else if (keysym == XK_g)
		color_screen(info, 0xff00);
	else if (keysym == XK_b)
		color_screen(info, 0xff);
	if (keysym == XK_Escape)
	{
		ft_printf("The %d key as been pressed\n", keysym);
		ft_free_and_out(info, 7, 1, "Success : ESC as been pressed\n");
	}
	ft_printf("The %d key as been pressed\n", keysym);
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
		0);
	return (0);
}
