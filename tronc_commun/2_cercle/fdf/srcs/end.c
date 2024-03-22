/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:19:38 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 02:15:15 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*void	ft_free_info(t_fdf *info)
{
	int	i;
	int	j;

	free(info->one_line);
	i = -1;
	while ((*info)->map[++i])
	{
		j = -1;
		while ((*info)->map[i][++j])
			free((*info)->map[i][j]);
		free((*info)->map[i]);
	}
	free(info);
}*/

void	ft_exit(char *erreur)
{
	int	len;

	len = ft_strlen(erreur);
	write(2, erreur , len);
	exit(0);
}

void	ft_error(char *one_line, char **map_2d, t_fdf *info, char *message)
{
	if (one_line)
		free(one_line);
	if (map_2d)
		ft_free_tab2d(map_2d);
	info = NULL;
	ft_exit(message);
}

