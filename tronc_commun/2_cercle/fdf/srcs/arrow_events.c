/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 06:01:59 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/06 06:22:31 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_arrow_right(t_fdf *info)
{
	int	x_offset;
	int	h;
	int	w;

	x_offset = 5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].x += x_offset;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

static void	ft_arrow_left(t_fdf *info)
{
	int	x_offset;
	int	h;
	int	w;

	x_offset = 5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].x -= x_offset;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

static void	ft_arrow_up(t_fdf *info)
{
	int	y_offset;
	int	h;
	int	w;

	y_offset = 5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].y -= y_offset;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

static void	ft_arrow_down(t_fdf *info)
{
	int	y_offset;
	int	h;
	int	w;

	y_offset = 5;
	h = 0;
	w = 0;
	while (h < info->height)
	{
		while (w < info->width)
		{
			info->map[h][w].y += y_offset;
			w++;
		}
		h++;
		w = 0;
	}
	ft_draw_map(info);
}

void	ft_arrow_event(int keysym, t_fdf *info)
{
	if (keysym == ARROW_LEFT)
		ft_arrow_left(info);
	else if (keysym == ARROW_UP)
		ft_arrow_up(info);
	else if (keysym == ARROW_RIGHT)
		ft_arrow_right(info);
	else if (keysym == ARROW_DOWN)
		ft_arrow_down(info);
}
