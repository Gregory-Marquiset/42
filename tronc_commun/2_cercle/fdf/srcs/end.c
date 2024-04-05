/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/05 09:41:17 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_map(t_fdf *info)
{
	int	h;

	h = 0;
	while (h < info->height)
	{
		free(info->map[h]);
		h++;
	}
	free(info->map);
}

void	ft_free_info(t_fdf *info)
{
	free(info->one_line);
	ft_free_tab2d(info->map_2d);
	mlx_destroy_display(info->mlx_ptr);
	ft_free_map(info);
}

void	ft_exit(int out, char *message)
{
	int	len;

	len = ft_strlen(message);
	if (len == 0 || out > 2 || out < 1)
	{
		write(2, "Erreur : message non valide\n", 28);
		exit(EXIT_FAILURE);
	}
	if (out == 2)
	{
		write(out, message, len);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(out, message, len);
		exit(EXIT_SUCCESS);
	}
}

void	ft_free_and_out(t_fdf *info, int flag, int out, char *message)
{
	if (flag == 1 || flag == 4 || flag > 4)
		free(info->one_line);
	if (flag == 2 || flag == 4 || flag > 4)
		ft_free_tab2d(info->map_2d);
	if (flag == 3 || flag > 4)
		ft_free_map(info);
	if (flag == 6)
	{
		mlx_destroy_display(info->mlx_ptr);
		free (info->mlx_ptr);
	}
	if (flag == 7)
	{
		mlx_destroy_image(info->mlx_ptr, info->img.img_ptr);
		mlx_destroy_window(info->mlx_ptr, info->win_ptr);
		mlx_destroy_display(info->mlx_ptr);
		free (info->mlx_ptr);
	}
	ft_exit(out, message);
}
