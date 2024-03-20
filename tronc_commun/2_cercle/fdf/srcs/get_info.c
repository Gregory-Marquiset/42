/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 21:24:56 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_fdf	*ft_make_info(int fd)
{
	char	*one_line;
	int		trigger;
	char	*line;
	char	**map_2d;
	t_fdf	*info;

	one_line = malloc(1);
	if (!one_line)
		return (0);
	one_line[0] = '\0';
	trigger = 1;
	while (trigger == 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			trigger = 0;
		else
			one_line = ft_strjoin(one_line, line, 2);
	}
	if (!ft_verif_map(one_line))
		return (free(one_line), 0);
	map_2d = ft_split(one_line, ' ', '\n');
		if (!map_2d)
			return (free(one_line), 0);
	info = ft_new_fdf(map_2d, one_line);
		if (!info)
			return (free(one_line), 0);
}

t_fdf	*ft_get_info(char *filename)
{
	int		fd;
	t_fdf	*info;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(info);
	info = ft_make_info(fd);
	close(fd);
}
