/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/23 13:22:47 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_get_color(char *str) // atoibase pour recuperer la couleur dans un int //
{
	char	*color;
	int		i;
	int		j;

	i = 0;
	if (!str)
		return (C_WHITE);
	while (str[i] != ',' && str[i])
		i++;
	if (str[i] == '\0')
		return (C_WHITE);
	color = malloc(9);
	if (!color)
		return (C_WHITE);
	i++;
	j = 0;
	while (j < 8)
		color[j++] = str[i++];
	color[8] = '\0';
	if (str[i] == '\0' && ft_isexa(color))
		return (color);
	else
		return (free (color), C_WHITE);
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
				ft_error(&info, "Erreur : join non reussi.\n");
		}
	}
}

void	ft_get_info(char *filename, t_fdf *info)
{
	ft_verif_extention(filename, "fdf");
	info->fd = open(filename, O_RDONLY);
	if (info->fd == -1)
		ft_exit("Erreur : echec de l'open du fd.\n");
	ft_get_one_line(&info);
	close(info->fd);
	info->map_2d = ft_split(info->one_line, ' ', '\n');
	if (!info->map_2d)
		ft_error(&info, "Erreur : echec creation de map_2d.\n");
	ft_new_fdf(&info);

}
