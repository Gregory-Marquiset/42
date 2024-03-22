/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 13:01:23 by gmarquis         ###   ########.fr       */
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
	int		i;
	int		j;

	info->map = malloc(info->width * sizeof(t_point **));
	if (!info->map)
		return (NULL);
	i = -1;
	while (info->map[++i])
	{
		info->map[i] = malloc(info->height * sizeof(t_point *));
		if (!info->map[i])
			return (NULL);
		j = 0;
		while (info.map[i][j])
		{
			info->map[i][j] = ft_new_point(i, j, info->map_2d[i][j]);
			j++;
		}
	}
}

void	ft_new_fdf(t_fdf *info)
{
	info->width = ft_countwords(info->one_line, ' ', ' ', '\n');
	info->height = ft_countwords(info->one_line, '\n', '\n', '\0');
	free (info->one_line);
	ft_make_map(&info);
}
