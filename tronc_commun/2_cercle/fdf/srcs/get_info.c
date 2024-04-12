/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/12 10:23:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
//		a finir		//
void	ft_get_color_modif(t_fdf *info, int y, int x)
{
	if (info->map[y][x].z > 0)
		info->map[y][x].c += 10;
	if (info->map[y][x].z < 0)
		info->map[y][x].c -= 10;
	if (info->map[y][x].c == BACKGROUND)
		info->map[y][x].c = info->map[y][x].c_ori;
}

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
		ft_exit(2, "Error: malloc failure for one_line.\n");
	info->one_line[0] = '\0';
	while (1)
	{
		line = get_next_line(info->fd); //		a gerer		//
		if (line == NULL)
			break ;
		else
		{
			info->one_line = ft_strjoin(info->one_line, line, 3);
			if (info->one_line == NULL)
				ft_free_and_out(info, 1, 2, "Error: join not successful.\n");
		}
	}
	close(info->fd);
	if (info->one_line[0] == '\0')
		ft_free_and_out(info, 1, 2, "Error: empty file.\n");
}

void	ft_get_map(t_fdf *info)
{
	int	w;
	int	h;
	int	i;

	info->map = malloc((info->height) * sizeof(t_point *));
	if (!info->map)
		ft_free_and_out(info, 1, 2, "Error: map malloc failure.\n");
	h = 0;
	i = 0;
	while (h < info->height)
	{
		info->map[h] = malloc((info->width) * sizeof(t_point));
		if (!info->map[h])
			ft_free_and_out(info, 4, 2, "Error: malloc of map[h] failed.\n");
		w = 0;
		while (w < info->width && info->map_2d[i])
		{
			info->map[h][w] = ft_init_point(w, h, info->map_2d[i]);
			w++;
			i++;
		}
		h++;
	}
}

void	ft_get_info(char *filename, t_fdf *info)
{
	ft_verif_extention(filename, ".fdf");
	info->fd = open(filename, O_RDONLY);
	if (info->fd == -1)
		ft_exit(2, "Error: Failed to open fd.\n");
	ft_get_one_line(info);
	ft_init_fdf(info);
}
