/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/23 11:11:13 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_map(t_point **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (&map[i][j])
		{
			free(&map[i][j]);
			j++;
		}
		free(&map[i]);
		i++;
	}
	free(map);
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
		ft_free_map(info->map);
	if (!info->erreur)
		 ft_exit(message);
	ft_exit(info->erreur);
}

