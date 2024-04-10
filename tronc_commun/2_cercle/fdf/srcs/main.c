/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 19:02:16 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void	ft_for_test(t_fdf *info)
{
	int	h = 0;
	int	w = 0;
	int	i = 0;

	ft_printf("height = %2d | width = %2d\none_line :\n%s\ninfo->map :\n", info->height, info->width, info->one_line);
	while (h < info->height)
	{
		w = 0;
		while (w < info->width)
		{
			ft_printf("point n.%2d =\nx.%2d y.%2d z.%2d\nv.%d c.%10d\n\n", i, info->map[h][w].x, info->map[h][w].y, info->map[h][w].z, info->map[h][w].v, info->map[h][w].c);
			w++;
			i++;
		}
		h++;
	}
}*/

int	main(int argc, char **argv)
{
	t_fdf	info;

	if (argc != 2)
		return (ft_exit(2, "Error: Bad argument format (./fdf file)\n"), 0);
	ft_get_info(argv[1], &info);

	ft_init_window(&info);

	info.img.img_ptr = mlx_new_image(info.mlx_ptr, WINDOW_WIDTH, WINDOW_WIDTH);
	info.img.img_pixels_ptr = mlx_get_data_addr(info.img.img_ptr, &info.img.bits_per_pixel, &info.img.line_len, &info.img.endian);

	ft_draw_map(&info);

	mlx_hook(info.win_ptr, 2, 1L << 0, &ft_handle_input, &info);
	mlx_hook(info.win_ptr, 17, 0L, &ft_handle_cross, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
