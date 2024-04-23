/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/22 23:11:59 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_instructs(t_fdf *info)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	x = info->w_width - 285;
	y = 0;
	mlx = info->mlx_ptr;
	win = info->win_ptr;
	mlx_string_put(mlx, win, x, y += 40, C_WHITE, "********************");
	mlx_string_put(mlx, win, x, y += 15, C_WHITE, "* Fil de Fer (FDF) *");
	mlx_string_put(mlx, win, x, y += 15, C_WHITE, "********************");
	mlx_string_put(mlx, win, x, y += 30, TEXT_COLOR, "Color: R G B N");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Reset: Space");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Change view: P I");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR,
		"Zoom in/out: + - x2 | * / x4");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Move Y: A D");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Move X: W S");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Move Z: Q E");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Rotate Y: 8 2");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Rotate X: 7 9");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Rotate Z: 4 6");
	mlx_string_put(mlx, win, x, y += 15, TEXT_COLOR, "Elevation: 0 1 3 5 .");
}

static void	ft_draw_instructs_bg(t_fdf *info)
{
	int	i;
	int	j;

	i = info->w_width - 300;
	while (i < info->w_width - 10)
	{
		j = 15;
		while (j < 265)
		{
			ft_pixel_put(info, i, j, MENU_BACKGROUND);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
		0);
	ft_draw_instructs(info);
}

static void	ft_draw_background(t_fdf *info)
{
	int	*image;
	int	i;

	ft_bzero(info->img.img_pixels_ptr, info->w_width * info->w_height
		* (info->img.bits_per_pixel / 8));
	image = (int *)(info->img.img_pixels_ptr);
	i = 0;
	while (i < info->w_height * info->w_width)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

static void	ft_draw_line(t_fdf *info, int y, int x, int flag)
{
	ft_init_drawl(info, y, x, flag);
	ft_init_grad(info);
	while (1)
	{
		ft_get_grad(info);
		if (info->drawl.delta_x == 0)
			if (info->grad.intermediate_color == -2147483648)
				info->grad.intermediate_color = info->drawl.c_start;
		ft_pixel_put(info, info->drawl.x0, info->drawl.y0,
			info->grad.intermediate_color);
		if (info->drawl.x0 == info->drawl.x1
			&& info->drawl.y0 == info->drawl.y1)
			break ;
		info->drawl.error2 = info->drawl.error;
		if (info->drawl.error2 > -info->drawl.delta_x)
		{
			info->drawl.error -= info->drawl.delta_y;
			info->drawl.x0 += info->drawl.step_x;
		}
		if (info->drawl.error2 < info->drawl.delta_y)
		{
			info->drawl.error += info->drawl.delta_x;
			info->drawl.y0 += info->drawl.step_y;
		}
	}
}

void	ft_draw_map(t_fdf *info)
{
	int	y;
	int	x;

	ft_draw_background(info);
	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			if (info->modif.active_iso == 1)
				ft_coordo_iso(info, y, x);
			else if (info->modif.active_para == 1)
				ft_coordo_para(info, y, x);
			if (x > 0)
				ft_draw_line(info, y, x, 0);
			if (y > 0 && info->map[y][x].v == 1)
				ft_draw_line(info, y, x, 1);
			x++;
		}
		y++;
	}
	ft_draw_instructs_bg(info);
}
