/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/19 05:50:15 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(void)
{
	t_fdf	*info;
	int		i;
	int		j;

	info = ft_new_fdf();
	ft_get_info("includes/test_maps/42.fdf", &info);
	ft_printf("one_line :\n%sWidth = %d\nHeight = %d\nmap :\n", info->one_line, info->width, info->height);
	i = -1;
	while (info->map[++i])
	{
		j = -1;
		while (info->map[i][++j])
		{
			if (i == 0 && j == 0)
				ft_printf("%d", info->map[i][j]->x);
			else
				ft_printf("%2d", info->map[i][j]->x);
		}
	}
	ft_free_info(&info);
	return (0);
}
