/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 04:04:40 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_get_color(char *str)
{
	if (!str)
		return (C_BASE);
	while (*str != ',' && *str != '\0')
		str++;
	str++;
	if (ft_isexa(str))
	{
		str += 2;
		return (ft_atoi_base(str, "0123456789ABCDEF"));
	}
	else
		return (C_BASE);
}

void	ft_get_one_line(t_fdf *info)
{
	int		trigger;
	char	*line;

	info->one_line = malloc(1);
	if (!info->one_line)
		ft_exit("Erreur : echec malloc pour one_line.\n");
	info->one_line[0] = '\0';
	trigger = 1;
	while (trigger == 1)
	{
		line = get_next_line(info->fd);	//	error du gnl potentiel virer le malloc de la static
		if (line == NULL)
			trigger = 0;
		else
		{
			info->one_line = ft_strjoin(info->one_line, line, 2);
			if (!info->one_line)
				ft_error(info, "Erreur : join non reussi.\n");
		}
	}
}

void	ft_get_info(char *filename, t_fdf *info)
{
	ft_verif_extention(filename, ".fdf");
	info->fd = open(filename, O_RDONLY);
	if (info->fd == -1)
		ft_exit("Erreur : echec de l'open du fd.\n");
	ft_get_one_line(info);
	close(info->fd);
	ft_new_fdf(info);

}
