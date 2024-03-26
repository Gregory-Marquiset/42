/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/26 21:07:59 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	ft_new_point(int x, int y, char *str)
{
	t_point	new;

	new.x = x;
	new.y = y;
	if (ft_strncmp(str, "V", 1))
	{
		new.z = ft_verif_cordo(str);
		new.v = 1;
		new.c = ft_get_color(str);
	}
	else
	{
		new.z = 0;
		new.v = 0;
		new.c = 0;
	}
	return (new);
}

void	ft_make_map(t_fdf *info)
{
	int	w;
	int	h;
	int	i;

	info->map = malloc(info->width * sizeof(t_point **));
	if (!info->map)
		ft_error(&info, "Erreu : echec malloc de map **.\n");
	w = -1;
	i = -1;
	while (++w < info->width)
	{
		info->map[w] = malloc(info->height * sizeof(t_point *));
		if (!info->map[w])
			ft_error(&info, "Erreu : echec malloc de map *.\n");
		h = -1;
		while (++h < info->height && info->map_2d[i])
			info->map[w][h] = ft_new_point(w, h, info->map_2d[++i]);
	}
}

void	ft_new_fdf(t_fdf *info)
{
	info->width = ft_countwords(info->one_line, ' ', ' ', '\n');
	info->height = ft_countwords(info->one_line, '\n', '\n', '\0');
	info->map_2d = ft_split_des_enfers(info->one_line, ' ', '\n', '\0');
	if (!info->map_2d)
		ft_error(&info, "Erreur : echec creation de map_2d.\n");
	ft_make_map(&info);

}
