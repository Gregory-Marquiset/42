/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 04:57:33 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_get_one_line(int fd)
{
	char	*one_line;
	int		trigger;
	char	*line;

	one_line = malloc(1);
	if (!one_line)
		return (ft_exit("Erreur : echec malloc pour one_line.\n"), NULL);
	one_line[0] = '\0';
	trigger = 1;
	while (trigger == 1)
	{
		line = get_next_line(fd);	//	error du gnl potentiel virer le malloc de la static
		if (line == NULL)
			trigger = 0;
		else
		{
			one_line = ft_strjoin(one_line, line, 2);
			if (!one_line)
				return (ft_error(line, NULL, NULL, "Erreur : join non reussi.\n"), NULL);
		}
	}
	return (one_line);
}

t_fdf	*ft_make_info(char *filename)
{
	int		fd;
	char	*one_line;
	char	**map_2d;
	t_fdf	*info;

	ft_verif_extention(filename, "fdf");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return(ft_exit("Erreur : echec de l'open.\n"), NULL);
	one_line = ft_get_one_line(fd);
	close(fd);
	map_2d = ft_split(one_line, ' ', '\n');
	if (!map_2d)
		return (ft_error(one_line, NULL, NULL, "Erreur : echec de split.\n"), NULL);
	info = ft_new_fdf(map_2d, one_line);
	if (!info)
		return (free(one_line), 0);
	return (ft_error(one_line, map_2d, info, "Succes : zero probleme.\n"), NULL);
}

t_fdf	*ft_get_info(char *filename)
{
	t_fdf	*info;

	info = ft_make_info(filename);
	return (0);
}
