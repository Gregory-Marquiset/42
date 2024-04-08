/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 10:19:14 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int z, int color)
{
	int offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8)) + (z * (img->line_len / WINDOW_WIDTH));
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

int	ft_calculate(int start, int end)
{
	if (start < end)
		return (1);
	else
		return (-1);
}

static void	ft_draw_line_pixels(t_fdf *info, int h, int w)
{
	info->drawl.delta_x = ft_absolute_nbr(info->drawl.x_end
			- info->drawl.x_start);
	info->drawl.delta_y = ft_absolute_nbr(info->drawl.y_end
			- info->drawl.y_start);
	while (info->drawl.x_start != info->drawl.x_end
		|| info->drawl.y_start != info->drawl.y_end)
	{
		my_pixel_put(&info->img, info->drawl.x_start, info->drawl.y_start, info->drawl.z_start, info->map[h][w].c);
		info->drawl.error2 = info->drawl.error;
		if (info->drawl.error2 > -info->drawl.delta_x)
		{
			info->drawl.error -= info->drawl.delta_y;
			info->drawl.x_start += info->drawl.step_x;
		}
		if (info->drawl.error2 < info->drawl.delta_y)
		{
			info->drawl.error += info->drawl.delta_x;
			info->drawl.y_start += info->drawl.step_y;
		}
	}
}

void	ft_draw_line(t_fdf *info, int h, int w, int flag)
{
	info->drawl.x_start = info->map[h][w].x;
	info->drawl.y_start = info->map[h][w].y;
	info->drawl.z_start = info->map[h][w].z;
	if (flag == 1)
	{
		info->drawl.x_end = info->map[h][w + 1].x;
		info->drawl.y_end = info->map[h][w + 1].y;
		info->drawl.z_end = info->map[h][w + 1].z;
	}
	else
	{
		info->drawl.x_end = info->map[h + 1][w].x;
		info->drawl.y_end = info->map[h + 1][w].y;
		info->drawl.z_end = info->map[h + 1][w].z;
	}
	info->drawl.delta_x = ft_absolute_nbr(info->drawl.x_end - info->drawl.x_start);
	info->drawl.delta_y = ft_absolute_nbr(info->drawl.y_end - info->drawl.y_start);
	info->drawl.delta_z = ft_absolute_nbr(info->drawl.z_end - info->drawl.z_start);
	info->drawl.step_x = ft_calculate(info->drawl.x_start, info->drawl.x_end);
	info->drawl.step_y = ft_calculate(info->drawl.y_start, info->drawl.y_end);
	info->drawl.step_z = ft_calculate(info->drawl.z_start, info->drawl.z_end);
	info->map[h][w].c += (info->drawl.delta_z * 100); // couleur en fonction de Z
	if (info->drawl.delta_x < info->drawl.delta_y)
		info->drawl.error = -info->drawl.delta_y / 2;
	else
		info->drawl.error = info->drawl.delta_x / 2;
	ft_draw_line_pixels(info, h, w);
}

void	ft_draw_map(t_fdf *info)
{
	int	h;
	int	w;

	ft_draw_background(info);
	h = 0;
	while (h < info->height)
	{
		w = 0;
		while (w < info->width)
		{
			if (w < info->width - 1)
				ft_draw_line(info, h, w, 1);
			if (h < info->height - 1)
				ft_draw_line(info, h, w, 2);
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
		0);
}
