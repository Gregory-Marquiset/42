/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 15:22:19 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_map(t_point **map, int height, int width)
{
	int	h;
	int	w;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			free(&map[h][w]);
			w++;
		}
		free(&map[h]);
		h++;
	}
	free(map);
}

void	ft_free_info(t_fdf *info)
{
	free (info->one_line);
	ft_free_tab2d(info->map_2d);
	ft_free_map(info->map, info->height, info->width);
	free(info);
}

void	ft_exit(char *erreur)
{
	int	len;

	len = ft_strlen(erreur);
	write(2, erreur , len);
	exit(0);
}

void	ft_error(t_fdf *info, char *message)
{
	if (info->one_line)
		free(info->one_line);
	if (info->map_2d)
		ft_free_tab2d(info->map_2d);
	if (info->map)
		ft_free_map(info->map, info->height, info->width);
	if (!info->erreur)
		 ft_exit(message);
	ft_exit(info->erreur);
}

