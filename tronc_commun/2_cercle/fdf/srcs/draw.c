/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/17 08:37:02 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	if(y <= WINDOW_HEIGHT && y >= 0 && x <= WINDOW_WIDTH)
	{
		offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8))
			+ (img->line_len / WINDOW_WIDTH);
		*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
	}
}
static void	draw_helper(t_fdf *info)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	y = 20;
	mlx = info->mlx_ptr;
	win = info->win_ptr;
	x = WINDOW_WIDTH - 270;
	mlx_string_put(info->mlx_ptr, info->win_ptr, 200, 200, C_RED, "************Usage*************");
	mlx_string_put(mlx, win, x, y + 30, TEXT_COLOR, "Disable usage   space");
	mlx_string_put(mlx, win, x, y + 55, TEXT_COLOR, "Move            < ^ v >");
	mlx_string_put(mlx, win, x, y + 80, TEXT_COLOR, "Move            q w a d");
	mlx_string_put(mlx, win, x, y + 105, TEXT_COLOR, "Zoom            + -");
	mlx_string_put(mlx, win, x, y + 130, TEXT_COLOR, "Scale up        page up");
	mlx_string_put(mlx, win, x, y + 155, TEXT_COLOR, "Scale down      page down");
	mlx_string_put(mlx, win, x, y + 180, TEXT_COLOR, "Angle           q e");
	mlx_string_put(mlx, win, x, y + 205, TEXT_COLOR, "Projection      p");
	mlx_string_put(mlx, win, x, y + 230, TEXT_COLOR, "Colortheme      c");
}

static void	draw_usage_bg(t_fdf *info)
{
	int i;
	int j;

	i = WINDOW_WIDTH - 300;
	while (i < WINDOW_WIDTH - 10)
	{
		j = 15;
		while (j < 285)
		{
			ft_pixel_put(&info->img, i, j, MENU_BACKGROUND);
			j++;
		}
		i++;
	}
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
		image[i] = BACKGROUND;
		i++;
	}
	draw_usage_bg(info);
	draw_helper(info);
}

void	ft_draw_line(t_fdf *info, int y, int x, int flag)
{
	double t;
	int interpolated_color;

	ft_init_drawl(info, y, x, flag);
	if (info->drawl.x0 > info->drawl.x1)
		info->drawl.step_x = -1;
	if (info->drawl.y0 > info->drawl.y1)
		info->drawl.step_y = -1;
	while (1)
	{
		t = (double)(info->drawl.delta_x - info->drawl.error) / (double)info->drawl.delta_x ;
		interpolated_color = info->drawl.c_start - info->drawl.c_end * t;

		ft_pixel_put(&info->img, info->drawl.x0, info->drawl.y0,
			info->map[y][x].c);

		if (info->drawl.x0 == info->drawl.x1 && info->drawl.y0 == info->drawl.y1)
			break ;

		info->drawl.error2 = 2 * info->drawl.error;

		if (info->drawl.error2 > -info->drawl.delta_y)
		{
			info->drawl.error -= info->drawl.delta_y;
			info->drawl.x0 += info->drawl.step_x;
		}

		if (info->drawl.error2 < info->drawl.delta_x)
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
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img_ptr, 0,
		0);
}
