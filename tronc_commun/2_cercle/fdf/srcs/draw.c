/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 19:51:23 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_pixel_put(t_img *img, int x, int y, int z, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8)) + (z
			* (img->line_len / WINDOW_WIDTH));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

static void	ft_draw_background(t_fdf *info)
{
	int	*image;
	int	i;

	ft_bzero(info->img.img_pixels_ptr, WINDOW_WIDTH * WINDOW_HEIGHT
		* (info->img.bits_per_pixel / 8));
	image = (int *)(info->img.img_pixels_ptr);
	i = 0;
	while (i < WINDOW_HEIGHT * WINDOW_WIDTH)
	{
		if (i % WINDOW_WIDTH < MENU_WIDTH)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

void ft_draw_map(t_fdf *info)
{
	int y;
	int x;

	y = 0;
	ft_draw_background(info);
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->modif.active_iso == 1)
				ft_coordo_iso(info, y, x);
			else if (info->modif.active_para == 1)
				ft_coordo_para(info, y, x);
			ft_verif_in_window(info, y, x);
			ft_pixel_put(&info->img, info->map[y][x].x, info->map[y][x].y,
							info->map[y][x].z, info->map[y][x].c);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
							0);
}
