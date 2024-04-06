/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:24:27 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/06 07:00:06 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void ft_rotate_map(t_fdf *info, double angle_x, double angle_y)
{
    double radian_angle_x = angle_x * M_PI / 180.0; // Conversion degrés en radians
    double radian_angle_y = angle_y * M_PI / 180.0;
    int h = 0;
    int w = 0;
    while (h < info->height)
    {
        while (w < info->width)
        {
            double old_x = info->map[h][w].x;
            double old_y = info->map[h][w].y;
            double old_z = info->map[h][w].z; // Assurez-vous que chaque point a une coordonnée Z
            // Rotation autour de l'axe Y (pour A et D)
            info->map[h][w].x = old_x * cos(radian_angle_x) - old_z * sin(radian_angle_x);
            info->map[h][w].z = old_x * sin(radian_angle_x) + old_z * cos(radian_angle_x);
            // Rotation autour de l'axe X (pour W et S)
            info->map[h][w].y = old_y * cos(radian_angle_y) - old_z * sin(radian_angle_y);
            info->map[h][w].z = old_y * sin(radian_angle_y) + old_z * cos(radian_angle_y);
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
		ft_rotate_map(info, 0, -ANGLE_INCREMENT);
	else if (keysym == MAIN_PAD_D)
		ft_rotate_map(info, 0, -ANGLE_INCREMENT);
	else if (keysym == MAIN_PAD_S)
		ft_rotate_map(info, ANGLE_INCREMENT, 0);
	else if (keysym == MAIN_PAD_W)
		ft_rotate_map(info, -ANGLE_INCREMENT, 0);
}
