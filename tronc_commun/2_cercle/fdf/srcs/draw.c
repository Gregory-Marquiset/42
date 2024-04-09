/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/09 06:52:53 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_pixel_put(t_img *img, int x, int y, int z, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8)) + (z
			* (img->line_len / WINDOW_WIDTH));
	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}


static void	ft_coordo_in_window(t_fdf *info, int y, int x)
{
	info->iso.tmp_x = (x - y) * cos(30 * M_PI / 180) * info->zoom + info->iso.dpl_x;
	info->iso.tmp_y = -info->map[y][x].z + (x + y) * sin(30 * M_PI / 180) * info->zoom + info->iso.dpl_y;
	info->iso.rotated_y_x = info->iso.tmp_y * cos(info->iso.rotation_x) - info->map[y][x].z * sin(info->iso.rotation_x);
	info->iso.rotated_z_x = info->iso.tmp_y * sin(info->iso.rotation_x) + info->map[y][x].z * cos(info->iso.rotation_x);
	info->iso.rotated_x_y = info->iso.tmp_x * cos(info->iso.rotation_y) + info->iso.rotated_z_x * sin(info->iso.rotation_y);
	info->iso.rotated_x_z = info->iso.rotated_x_y * cos(info->iso.rotation_z) - info->iso.rotated_y_x * sin(info->iso.rotation_z);
	info->iso.rotated_y_z = info->iso.rotated_x_y * sin(info->iso.rotation_z) + info->iso.rotated_y_x * cos(info->iso.rotation_z);
	info->iso.iso_x = info->iso.rotated_x_z;
	info->iso.iso_y = info->iso.rotated_y_z;
	info->iso.iso_x += (WINDOW_WIDTH - info->width) / 2;
	info->iso.iso_y += (WINDOW_HEIGHT - info->height) / 2;
	if (info->iso.iso_x < 0)
		info->iso.iso_x = 0;
	if (info->iso.iso_x >= WINDOW_WIDTH)
		info->iso.iso_x = WINDOW_WIDTH - 1;
	if (info->iso.iso_y < 0)
		info->iso.iso_y = 0;
	if (info->iso.iso_y >= WINDOW_HEIGHT)
		info->iso.iso_y = WINDOW_HEIGHT - 1;
	info->map[y][x].x = info->iso.iso_x;
	info->map[y][x].y = info->iso.iso_y;
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

void ft_draw_line(t_fdf *info, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (x0 != x1 || y0 != y1)
    {
        ft_pixel_put(&info->img, x0, y0, info->map[y0][x0].z, color);
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
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
			ft_coordo_in_window(info, y, x);
			ft_pixel_put(&info->img, info->iso.iso_x, info->iso.iso_y,
							info->map[y][x].z, info->map[y][x].c);
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
							0);
}
