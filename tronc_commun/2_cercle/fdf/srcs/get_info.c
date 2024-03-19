/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 04:17:46 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/19 05:29:12 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_get_l_w_h(t_fdf **info)
{
	char	*line;
	int		trigger;

	trigger = 1;
	(*info)->one_line = malloc(1);
	if (!(*info)->one_line)
		ft_error(info);
	(*info)->one_line[0] = '\0';
	while (trigger == 1)
	{
		line = get_next_line((*info)->fd);
		if (line == NULL)
			trigger = 0;
		else
			(*info)->one_line = ft_strjoin((*info)->one_line, line, 2);
	}
	(*info)->width = ft_countwords((*info)->one_line, ' ', '\n');
	(*info)->height = ft_countwords((*info)->one_line, '\n', '\0');
}

void	ft_get_info(char *filename, t_fdf **info)
{
	(*info)->fd = open(filename, O_RDONLY);
	if ((*info)->fd == -1)
		ft_error(info);
	ft_get_l_w_h(info);
	close((*info)->fd);
	ft_make_map(info, (*info)->one_line);
}
