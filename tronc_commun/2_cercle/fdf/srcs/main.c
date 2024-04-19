/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/19 08:12:34 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	info;

	if (argc != 2)
		return (ft_exit(2, "Error: Bad argument format (./fdf file)\n"), 0);
	ft_get_info(argv[1], &info);
	ft_init_window(&info);
	info.img.img_ptr = mlx_new_image(info.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	info.img.img_pixels_ptr = mlx_get_data_addr(info.img.img_ptr,
			&info.img.bits_per_pixel, &info.img.line_len, &info.img.endian);
	ft_draw_map(&info);
	mlx_hook(info.win_ptr, 2, 1L << 0, &ft_handle_input, &info);
	mlx_hook(info.win_ptr, 17, 0L, &ft_handle_cross, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
