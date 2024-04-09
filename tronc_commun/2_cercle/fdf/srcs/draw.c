/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/09 08:43:01 by gmarquis         ###   ########.fr       */
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

void draw_line(t_fdf *info, int y, int x)
{
    // Condition de terminaison de la récursion
    if (p1->x == p2->x && p1->y == p2->y)
        return;

    // Dessiner le pixel correspondant à p1
    ft_pixel_put(img, p1->x, p1->y, p1->z, p1->c);

    // Calculer la pente de la ligne
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
    double increment_x = dx / steps;
    double increment_y = dy / steps;

    // Déplacer progressivement le long de la ligne
    double x = p1->x;
    double y = p1->y;
    for (int i = 0; i < steps; i++)
    {
        x += increment_x;
        y += increment_y;
        ft_pixel_put(img, round(x), round(y), p1->z, p1.c);
    }

    // Appel récursif avec le point suivant
    draw_line(p2, p3, img);
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
			if (x < info->width - 1)
                draw_line(info, y, x);
            if (y < info->height - 1)
                draw_line(info, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
							0);
}
