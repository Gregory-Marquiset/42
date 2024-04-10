/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:04:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 18:14:21 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_coordo_para(t_fdf *info, int y, int x)
{
    info->map[y][x].x = x * info->modif.zoom + info->modif.dpl_x;
	info->map[y][x].y = 0;
    info->map[y][x].x += (WINDOW_WIDTH - info->width * info->modif.zoom) / 2;
    info->map[y][x].y += (WINDOW_HEIGHT - info->height * info->modif.zoom) / 2;
}

void	ft_coordo_iso(t_fdf *info, int y, int x)
{
	info->modif.tmp_x = (x - y) * cos(30 * M_PI / 180) * info->modif.zoom + info->modif.dpl_x;
	info->modif.tmp_y = -info->map[y][x].z + (x + y) * sin(30 * M_PI / 180) * info->modif.zoom + info->modif.dpl_y;
	info->iso.rotated_y_x = info->modif.tmp_y * cos(info->modif.rotation_x) - info->map[y][x].z * sin(info->modif.rotation_x);
	info->iso.rotated_z_x = info->modif.tmp_y * sin(info->modif.rotation_x) + info->map[y][x].z * cos(info->modif.rotation_x);
	info->iso.rotated_x_y = info->modif.tmp_x * cos(info->modif.rotation_y) + info->iso.rotated_z_x * sin(info->modif.rotation_y);
	info->iso.rotated_x_z = info->iso.rotated_x_y * cos(info->modif.rotation_z) - info->iso.rotated_y_x * sin(info->modif.rotation_z);
	info->iso.rotated_y_z = info->iso.rotated_x_y * sin(info->modif.rotation_z) + info->iso.rotated_y_x * cos(info->modif.rotation_z);
	info->map[y][x].x = info->iso.rotated_x_z;
	info->map[y][x].y = info->iso.rotated_y_z;
	info->map[y][x].x += (WINDOW_WIDTH - info->width) / 2;
	info->map[y][x].y += (WINDOW_HEIGHT - info->height) / 2;
}

/*void	ft_coordo_normal(t_fdf *info, int y, int x)
{
    info->map[y][x].x = x * info->modif.zoom + info->modif.dpl_x;
    info->map[y][x].y = -info->map[y][x].z + y * info->modif.zoom + info->modif.dpl_y;
    info->modif.tmp_y = info->map[y][x].y * cos(info->modif.rotation_x) - info->map[y][x].z * sin(info->modif.rotation_x);
    info->modif.tmp_z = info->map[y][x].y * sin(info->modif.rotation_x) + info->map[y][x].z * cos(info->modif.rotation_x);
    info->map[y][x].y = info->modif.tmp_y;
    info->map[y][x].z = info->v.tmp_z;
    info->modif.tmp_x = info->map[y][x].x * cos(info->modif.rotation_y) + info->map[y][x].z * sin(info->v.rotation_y);
    info->modif.tmp_z = info->map[y][x].x * sin(info->modif.rotation_y) + info->map[y][x].z * cos(info->modif.rotation_y);
    info->map[y][x].x = info->modif.tmp_x;
    info->map[y][x].z = info->modif.tmp_z;
    info->modif.tmp_x = info->map[y][x].x * cos(info->modif.rotation_z) - info->map[y][x].y * sin(info->modif.rotation_z);
    info->modif.tmp_y = info->map[y][x].x * sin(info->modif.rotation_z) + info->map[y][x].y * cos(info->modif.rotation_z);
    info->map[y][x].x = info->modif.tmp_x;
    info->map[y][x].y = info->modif.tmp_y;
    info->map[y][x].x += (WINDOW_WIDTH - info->width * info->zoom) / 2;
    info->map[y][x].y += (WINDOW_HEIGHT - info->height * info->zoom) / 2;
}*/
void	ft_coordo_normal(t_fdf *info, int y, int x)
{
    // Calcul des coordonnées dans la fenêtre sans transformation isométrique
    info->map[y][x].x = x * info->modif.zoom + info->modif.dpl_x;
    info->map[y][x].y = y * info->modif.zoom + info->modif.dpl_y;

    // Rotation autour de l'axe X
    double rotated_y = info->map[y][x].y * cos(info->modif.rotation_x) - info->map[y][x].z * sin(info->modif.rotation_x);
    double rotated_z = info->map[y][x].y * sin(info->modif.rotation_x) + info->map[y][x].z * cos(info->modif.rotation_x);
    info->map[y][x].y = rotated_y;
    info->map[y][x].z = rotated_z;

    // Rotation autour de l'axe Y
    double original_x = info->map[y][x].x; // Sauvegarde de la valeur originale de x
    double rotated_x = original_x * cos(info->modif.rotation_y) + info->map[y][x].z * sin(info->modif.rotation_y);
    rotated_z = -original_x * sin(info->modif.rotation_y) + info->map[y][x].z * cos(info->modif.rotation_y);
    info->map[y][x].x = rotated_x;
    info->map[y][x].z = rotated_z;

    // Rotation autour de l'axe Z
    rotated_x = info->map[y][x].x * cos(info->modif.rotation_z) - info->map[y][x].y * sin(info->modif.rotation_z);
    rotated_y = info->map[y][x].x * sin(info->modif.rotation_z) + info->map[y][x].y * cos(info->modif.rotation_z);
    info->map[y][x].x = rotated_x;
    info->map[y][x].y = rotated_y;

    // Ajout des décalages pour centrer l'image dans la fenêtre
    info->map[y][x].x += (WINDOW_WIDTH - info->width * info->modif.zoom) / 2;
    info->map[y][x].y += (WINDOW_HEIGHT - info->height * info->modif.zoom) / 2;
}
