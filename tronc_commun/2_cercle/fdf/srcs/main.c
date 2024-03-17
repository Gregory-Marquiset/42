/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/17 21:41:31 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_get_width_height(int fd, int *width, int *height)
{
	char	*line;
	int		trigger;
	char	*map;

	*width = 0;
	*height = 0;
	trigger = 1;
	map = malloc(1);
	if (!map)
		return (0);
	map[0] = '\0';
	while (trigger == 1)
	{
		line = get_next_line(fd);
		*height += ft_count_n(line, '\n');
		if (line == NULL)
			trigger = 0;
		else
			map = ft_strjoin(map, line);
		free(line);
	}
	*width = ft_countwords(map, ' ', '\n');
	return (map);
}

t_point	*read_map(char *filename, int *width, int *height)
{
	int		fd;
	char	*one_line;
	t_point	*map;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Erreur : Impossible d'ouvrir le fichier.\n");
		exit(EXIT_FAILURE);
	}
	one_line = ft_get_width_height(fd, width, height);
	ft_printf("%s", one_line);
	map = malloc((*width) * (*height) * sizeof(t_point));
	if (map == NULL)
	{
		ft_printf("Erreur : Échec de l'allocation de mémoire.\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	free(one_line);
	return (map);
}

int	main(void)
{
	int		width;
	int		height;
	t_point	*map;

	map = read_map("includes/test_maps/42.fdf", &width, &height);
	ft_printf("Width = %2d\nHeight = %d\n", width, height);
	free(map);
	return (0);
}
