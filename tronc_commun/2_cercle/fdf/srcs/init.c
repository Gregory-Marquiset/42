/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 05:38:42 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	*ft_new_point(int x, int y, char *str)
{
	t_point	*new;

	if (!ft_verif_cordo(str));
		return (NULL/*a gerer*/);
	new = malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	if (ft_strncmp(str, 'V', 1))
	{
		new->z = ft_get_z(str);
		new->v = 1;
		new->c = ft_get_color(str);
	}
	else
	{
		new->z = 0;
		new->v = 0;
		new->c = 0;
	}
	return (new);
}

t_point	***ft_make_map(int width, int height, char **map_2d)
{
	t_point	***map;
	int		i;
	int		j;

	map = malloc(width * sizeof(t_point **));
	if (!map)
		return (NULL/*a gerer*/);
	i = -1;
	while (map[++i])
	{
		map[i] = malloc(height * sizeof(t_point *));
		if (!map[i])
			return (NULL/*a gerer*/);
		j = -1;
		while (map[i][++j])
		{
			map[i][j] = ft_new_point(i, j, map_2d[i][j]);
			if (!map[i][j])
				return (NULL/*a gerer*/);
		}
	}
	return (map);
}

t_fdf	*ft_new_fdf(char **map_2d, char *one_line)
{
	t_fdf	*info;

	info = malloc(sizeof * info);
	if (!info)
		return (0);
	info->width = ft_countwords(one_line, ' ', ' ', '\n');
	info->height = ft_countwords(one_line, '\n', '\n', '\0');
	free (one_line);
	info->map = ft_make_map(info->width, info->height, map_2d);
	if (!info->map)
		return (NULL/*a gerer*/);
	return (info);
}
