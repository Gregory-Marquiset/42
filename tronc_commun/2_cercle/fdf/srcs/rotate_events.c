/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:24:27 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 12:41:31 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void ft_rotate_map(t_fdf *info, double angle_x, double angle_y)
{
    double radian_angle_x = angle_x * M_PI / 180.0;
    double radian_angle_y = angle_y * M_PI / 180.0;
    double center_x = info->width / 2.0;
    double center_y = info->height / 2.0;
    double center_z = 0.0;
    int h = 0;
    int w = 0;
    while (h < info->height)
    {
        while (w < info->width)
        {
            double old_x = info->map[h][w].x;
            double old_y = info->map[h][w].y;
            double old_z = info->map[h][w].z;
            double translated_x = old_x - center_x;
            double translated_y = old_y - center_y;
            double translated_z = old_z - center_z;
            double new_y = translated_y * cos(radian_angle_x) - translated_z * sin(radian_angle_x);
            double new_z = translated_y * sin(radian_angle_x) + translated_z * cos(radian_angle_x);
            double new_x = translated_x * cos(radian_angle_y) + translated_z * sin(radian_angle_y);
            new_z = -translated_x * sin(radian_angle_y) + translated_z * cos(radian_angle_y);
            info->map[h][w].x = new_x + center_x;
            info->map[h][w].y = new_y + center_y;
            info->map[h][w].z = new_z + center_z;
            w++;
        }
        h++;
        w = 0;
    }
    ft_draw_map(info);
}

void	ft_rotate_event(int keysym, t_fdf *info)
{
	if (keysym == MAIN_PAD_A)
		ft_rotate_map(info, 0, FACTOR);
	else if (keysym == MAIN_PAD_D)
		ft_rotate_map(info, 0, -FACTOR);
	else if (keysym == MAIN_PAD_S)
		ft_rotate_map(info, FACTOR, 0);
	else if (keysym == MAIN_PAD_W)
		ft_rotate_map(info, -FACTOR, 0);
}
