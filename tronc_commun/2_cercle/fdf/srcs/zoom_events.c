/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:10:30 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 10:24:06 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_zoom_in(t_fdf *info)
{
	double zoom_factor;
	int h;
	int w;

	zoom_factor = 2;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].y *= zoom_factor;
			info->map[h][w].x *= zoom_factor;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}


static void	ft_zoom_out(t_fdf *info)
{
	double zoom_factor;
	int h;
	int w;

	zoom_factor = 0.5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].y *= zoom_factor;
			info->map[h][w].x *= zoom_factor;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

static void	ft_up_z(t_fdf *info)
{
	double zoom_factor;
	int h;
	int w;

	zoom_factor = 2;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			if (info->map[h][w].z != 0)
				info->map[h][w].z *= zoom_factor;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

static void	ft_down_z(t_fdf *info)
{
	double zoom_factor;
	int h;
	int w;

	zoom_factor = 0.5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			if (info->map[h][w].z != 0)
				info->map[h][w].z *= zoom_factor;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

void	ft_zoom_event(int keysym, t_fdf *info)
{
	if (keysym == NUM_PAD_PLUS)
		ft_zoom_in(info);
	else if (keysym == NUM_PAD_MINUS)
		ft_zoom_out(info);
	else if (keysym == NUM_PAD_MULT)
		ft_up_z(info);
	else if (keysym == NUM_PAD_DIVIDE)
		ft_down_z(info);
}
