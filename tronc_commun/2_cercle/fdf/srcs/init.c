/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 12:15:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_init_window(t_fdf *info)
{
	info->mlx_ptr = mlx_init();
	if (info->mlx_ptr == NULL)
		ft_free_and_out(info, 5, 2, "Erreur : Impossible d'initialiser la connexion avec le serveur graphique.\n");
	info->win_ptr = mlx_new_window(info->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (info->win_ptr == NULL)
		ft_free_and_out(info, 6, 2, "Erreur : window non initialiser.\n");
}

t_point	ft_new_point(int x, int y, char *str)
{
	t_point	new;

	new.x = x;
	new.y = y;
	if (!str || !ft_strncmp(str, "V", 1))
	{
		new.z = 0;
		new.z_base = 0;
		new.v = 0;
		new.c = 0;
	}
	else
	{
		new.z = ft_verif_cordo(str);
		new.z_base = new.z;
		new.v = 1;
		new.c = ft_get_color(str);
	}
	return (new);
}

void	ft_make_map(t_fdf *info)
{
	int	w;
	int	h;
	int	i;

	info->map = malloc((info->height) * sizeof(t_point *));
	if (!info->map)
		ft_free_and_out(info, 1, 2, "Erreur : echec malloc de map.\n");
	h = 0;
	i = 0;
	while (h < info->height)
	{
		info->map[h] = malloc((info->width) * sizeof(t_point));
		if (!info->map[h])
			ft_free_and_out(info, 4, 2, "Erreur : echec malloc de map[h].\n");
		w = 0;
		while (w < info->width && info->map_2d[i])
		{
			info->map[h][w] = ft_new_point(w, h, info->map_2d[i]);
			w++;
			i++;
		}
		h++;
	}
}

void	ft_new_fdf(t_fdf *info)
{
	info->height = ft_countwords(info->one_line, '\n', '\n', '\0');
	info->width = ft_countwords(info->one_line, ' ', ' ', '\n');
	info->map_2d = ft_split(info->one_line, ' ', '\n');
	if (!info->map_2d)
		ft_free_and_out(info, 1, 2, "Erreur : echec creation de map_2d.\n");
	ft_make_map(info);
}
