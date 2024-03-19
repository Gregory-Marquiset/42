/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:06:15 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/19 06:03:02 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*ft_new_point(int y, int x, char *str)
{
	t_map	*new;

	new = malloc(sizeof * new);
	if (!new)
		return (NULL);
	new->x = x;
	new->y = y;
	new->z = ft_atoi(str);
	new->v = ft_strncmp(str, "V", 1);
	return (new);
}

t_fdf	*ft_new_fdf(void)
{
	t_fdf	*info;

	info = malloc(sizeof * info);
	if (!info)
		return (0);
	info->fd = 0;
	info->one_line = NULL;
	info->height = 0;
	info->width = 0;
	info->map = NULL;
	return (info);
}

void	ft_make_map(t_fdf **info, char	*line_tmp)
{
	int		h;
	int		w;

	(*info)->map = malloc(((*info)->height) * sizeof(t_map *));
	if (!(*info)->map)
		ft_error(info);
	h = -1;
	while ((*info)->map[++h])
	{
		(*info)->map[h] = malloc(((*info)->width) * sizeof(t_map *));
		if (!(*info)->map[w])
			ft_error(info);
		w = -1;
		while ((*info)->map[h][++w])
		{
			while (*line_tmp == ' ')
				line_tmp++;
			(*info)->map[h][w] = ft_new_point(h, w, line_tmp);
			while (*line_tmp != ' ')
				line_tmp++;
		}
	}
}
