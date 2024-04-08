/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 14:16:20 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_color(char *str)
{
	int	i;

	if (!str)
		return (C_BASE);
	if (!ft_contain_n(str, ','))
		return (C_BASE);
	i = 0;
	while (str[i] != ',' && str[i] != '\0')
		i++;
	i++;
	if (ft_isexa(str + i))
	{
		i += 2;
		return (ft_atoi_base(str + i, "0123456789ABCDEF"));
	}
	else
		return (C_BASE);
}

void	ft_get_one_line(t_fdf *info)
{
	char	*line;

	info->one_line = malloc(1);
	if (!info->one_line)
		ft_exit(2, "Erreur : echec malloc pour one_line.\n");
	info->one_line[0] = '\0';
	while (1)
	{
		line = get_next_line(info->fd);
		if (line == NULL)
			break;
		else
		{
			info->one_line = ft_strjoin(info->one_line, line, 3);
			if (info->one_line == NULL)
				ft_free_and_out(info, 1, 2, "Erreur : join non reussi.\n");
		}
	}
	close(info->fd);
	if (info->one_line[0] == '\0')
		ft_free_and_out(info, 1, 2, "Erreur : fichier vide.\n");
}

void	ft_get_info(char *filename, t_fdf *info)
{
	ft_verif_extention(filename, ".fdf");
	info->fd = open(filename, O_RDONLY);
	if (info->fd == -1)
		ft_exit(2, "Erreur : echec de l'open du fd.\n");
	ft_get_one_line(info);
	ft_new_fdf(info);
}
