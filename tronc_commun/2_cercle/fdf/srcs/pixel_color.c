/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:18:39 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/22 23:14:40 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_fdf *info, int x, int y, int color)
{
	int	offset;

	if (y <= info->w_height - 1 && y >= 1 && x <= info->w_width - 1 && x >= 1)
	{
		offset = (y * info->img.line_len) + (x * (info->img.bits_per_pixel / 8))
			+ (info->img.line_len / info->w_width);
		*((unsigned int *)(offset + info->img.img_pixels_ptr)) = color;
	}
}
