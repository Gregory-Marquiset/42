/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 01:18:39 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/19 01:28:22 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	if (y <= WINDOW_HEIGHT - 1 && y >= 1 && x <= WINDOW_WIDTH - 1 && x >= 1)
	{
		offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8))
			+ (img->line_len / WINDOW_WIDTH);
		*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
	}
}
