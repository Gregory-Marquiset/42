/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 19:05:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/19 02:02:10 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	ft_draw_instructs(t_fdf *info)
{
	int		x;
	int		y;
	void	*mlx;
	void	*win;

	x = WINDOW_WIDTH - 285;
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

	i = WINDOW_WIDTH - 300;
	while (i < WINDOW_WIDTH - 10)
	{
		j = 15;
		while (j < 265)
		{
			ft_pixel_put(&info->img, i, j, MENU_BACKGROUND);
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

	ft_bzero(info->img.img_pixels_ptr, WINDOW_WIDTH * WINDOW_HEIGHT
		* (info->img.bits_per_pixel / 8));
	image = (int *)(info->img.img_pixels_ptr);
	i = 0;
	while (i < WINDOW_HEIGHT * WINDOW_WIDTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

static void	ft_draw_line(t_fdf *info, int y, int x, int flag)
{
	ft_init_drawl(info, y, x, flag);
	if (info->drawl.x0 > info->drawl.x1)
		info->drawl.step_x = -1;
	if (info->drawl.y0 > info->drawl.y1)
		info->drawl.step_y = -1;

	// Calculer la variation de couleur par pixel
	int delta_red = (info->drawl.c_start >> 16) - (info->drawl.c_end >> 16);
	int delta_green = ((info->drawl.c_start >> 8) & 0xFF) - ((info->drawl.c_end >> 8) & 0xFF);
	int delta_blue = (info->drawl.c_start & 0xFF) - (info->drawl.c_end & 0xFF);

	// Nombre total de pixels dans la ligne
	int num_pixels = ft_absolute_nbr(info->drawl.x1 - info->drawl.x0);
	if (num_pixels == 0) // Si la ligne est verticale, le nombre de pixels est la différence sur l'axe y
		num_pixels = ft_absolute_nbr(info->drawl.y1 - info->drawl.y0);

	int i = 1;
	while (i < num_pixels)
	{
		// Calculer la proportion du chemin parcouru le long de la ligne
		double progress = (double)i / num_pixels;

		// Calculer la couleur intermédiaire
		int intermediate_red = (info->drawl.c_start >> 16) + (delta_red * progress);
		int intermediate_green = (info->drawl.c_start >> 8 & 0xFF) + (delta_green * progress);
		int intermediate_blue = (info->drawl.c_start & 0xFF) + (delta_blue * progress);
		int intermediate_color = (intermediate_red << 16) | (intermediate_green << 8) | intermediate_blue;

		// Dessiner le pixel avec la couleur intermédiaire
		ft_pixel_put(&info->img, info->drawl.x0, info->drawl.y0, intermediate_color);

		// Mise à jour des coordonnées pour le prochain pixel
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

		i++;
	}
}

/*static void	ft_draw_line(t_fdf *info, int y, int x, int flag)
{
	ft_init_drawl(info, y, x, flag);
	if (info->drawl.x0 > info->drawl.x1)
		info->drawl.step_x = -1;
	if (info->drawl.y0 > info->drawl.y1)
		info->drawl.step_y = -1;
	while (1)
	{
		ft_pixel_put(&info->img, info->drawl.x0, info->drawl.y0,
			info->map[y][x].c);
		if (info->drawl.x0 == info->drawl.x1
			&& info->drawl.y0 == info->drawl.y1)
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
}*/

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
