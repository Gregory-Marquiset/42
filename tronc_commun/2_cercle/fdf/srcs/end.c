/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 20:40:25 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_free_info(t_fdf *info)
{
	//int	i;
	//int	j;

	free(info->one_line);
	//i = -1;
	/*while ((*info)->map[++i])
	{
		j = -1;
		while ((*info)->map[i][++j])
			free((*info)->map[i][j]);
		free((*info)->map[i]);
	}*/
	free(info);
}

void	ft_error(t_fdf *info)
{
	if (info->fd == -1)
		ft_printf("Erreur : Impossible d'ouvrir le fichier.\n");
	if (info->one_line)
		free(info->one_line);
	if (info)
		free(info);
	exit(EXIT_FAILURE);
}
