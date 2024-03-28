/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:09:00 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 19:39:57 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	char	**str;
	int		i;

	if (argc != 2)
		return (0);
	str = ft_split(argv[1], ' ', '\n');
	i = 0;
	while (str[i])
	{
		ft_printf("%s\n", str[i]);
		i++;
	}
	ft_free_tab2d(str);
	return (0);
}

//		test tab de tab de struct		//
/*typedef struct s_map
{
	int	x;
	int	y;
	int	z;
	int	v;
}		t_map;

int	main(int ac, char **av)
{
	t_map	***map;
	int	width = -1;
	int	height;
	int	value;
	int	visible;

	map = malloc(6 * sizeof(t_map **));
	if (!map)
		return (printf("KO.1\n"), 0);
	value = 0;
	visible = 1;
	while (++width < 6)
	{
		height = -1;
		map[width] = malloc(3 * sizeof(t_map *));
		if (!map[width])
			return (printf("KO.2\n"), 0);
		while (++height < 3)
		{
			map[width][height] = malloc(sizeof(t_map));
			if (!map[width][height])
				return (printf("KO.3\n"), 0);
			map[width][height]->x = width;
			map[width][height]->y = height;
			map[width][height]->z = value;
			map[width][height]->v = visible;
			if (value == 0)
				value = 10;
			else
				value = 0;
			if (visible == 0)
				visible = 1;
			else
				visible = 0;
		}
	}
	width = -1;
	while (++width < 6)
	{
		height = -1;
		while (++height < 3)
		{
			printf("map[%d][%d] [x = %2d] [y = %2d] [z = %2d] [v = %2d]\n",
				width, height, map[width][height]->x, map[width][height]->y,
				map[width][height]->z ,map[width][height]->v);
		}
	}
}*/
