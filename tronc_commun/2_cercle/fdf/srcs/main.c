/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/29 06:16:26 by gmarquis         ###   ########.fr       */
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
		return (ft_exit("Erreur : mauvais format d'argument (./fdf map)\n"), 0);
	ft_get_info(argv[1], &info);
	info.mlx_ptr = mlx_init();
	if (info.mlx_ptr == NULL)
		ft_error(&info, 5, "Erreur : Impossible d'initialiser la connexion avec le serveur graphique.\n");
	ft_init_window(&info); // protection
	ft_set_key_hook(&info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
