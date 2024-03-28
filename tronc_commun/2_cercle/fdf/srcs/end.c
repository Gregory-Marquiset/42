/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 16:38:31 by gmarquis         ###   ########.fr       */
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
	ft_free_map(info);
}

void	ft_exit(char *erreur)
{
	int	len;

	len = ft_strlen(erreur);
	write(2, erreur, len);
	exit(0);
}

void	ft_error(t_fdf *info, char *message)
{
	if (info->one_line)
		free(info->one_line);
	if (info->map_2d)
		ft_free_tab2d(info->map_2d);
	if (info->map)
		ft_free_map(info);
	ft_exit(message);
}
