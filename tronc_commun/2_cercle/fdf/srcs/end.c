/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 19:18:46 by gmarquis         ###   ########.fr       */
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
	write(1, "Succes!\n", 8);
	exit(0);
}

void	ft_exit(char *error)
{
	int	len;

	len = ft_strlen(error);
	write(2, error, len);
	exit(0);
}

void	ft_error(t_fdf *info, int flag, char *message)
{
	if (flag == 1 || flag == 4 || flag == 5)
		free(info->one_line);
	if (flag == 2 || flag == 4 || flag == 5)
		ft_free_tab2d(info->map_2d);
	if (flag == 3 || flag == 5)
		ft_free_map(info);
	ft_exit(message);
}
