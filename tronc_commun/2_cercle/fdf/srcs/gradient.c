/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 04:53:39 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/19 06:10:53 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_grad(t_fdf *info)
{
	info->grad.progress = (double)ft_absolute_nbr(info->drawl.x1
			- info->drawl.x0) / info->drawl.delta_x;
	info->grad.intermediate_red = (info->drawl.c_start >> 16)
		+ (info->grad.delta_red * info->grad.progress);
	info->grad.intermediate_green = ((info->drawl.c_start >> 8) & 0xFF)
		+ (info->grad.delta_green * info->grad.progress);
	info->grad.intermediate_blue = (info->drawl.c_start & 0xFF)
		+ (info->grad.delta_blue * info->grad.progress);
	info->grad.intermediate_color = (info->grad.intermediate_red << 16)
		| (info->grad.intermediate_green << 8) | info->grad.intermediate_blue;
}

void	ft_init_grad(t_fdf *info)
{
	if (info->drawl.delta_x > info->drawl.delta_y)
		info->drawl.error = info->drawl.delta_x / 2;
	if (info->drawl.x0 < info->drawl.x1)
		info->drawl.step_x = 1;
	if (info->drawl.y0 < info->drawl.y1)
		info->drawl.step_y = 1;
	info->grad.delta_red = (info->drawl.c_end >> 16)
		- (info->drawl.c_start >> 16);
	info->grad.delta_green = ((info->drawl.c_end >> 8) & 0xFF)
		- ((info->drawl.c_start >> 8) & 0xFF);
	info->grad.delta_blue = (info->drawl.c_end & 0xFF)
		- (info->drawl.c_start & 0xFF);
	info->grad.progress = 0;
	info->grad.intermediate_red = 0;
	info->grad.intermediate_green = ((info->drawl.c_start >> 8) & 0xFF)
		+ (info->grad.delta_green * info->grad.progress);
	info->grad.intermediate_blue = (info->drawl.c_start & 0xFF)
		+ (info->grad.delta_blue * info->grad.progress);
	info->grad.intermediate_color = (info->grad.intermediate_red << 16)
		| (info->grad.intermediate_green << 8) | info->grad.intermediate_blue;
}
