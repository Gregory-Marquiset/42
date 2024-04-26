/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/26 03:08:12 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		trigger;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	trigger = 1;
	printf("\033[36;01m| vv | le texte demarre a la ligne d'en dessou en blanc | vv |\033[00m\n");
	while (trigger == 1)
	{
		line = get_next_line(fd, argv[2][0]);
		if (line != NULL)
		printf("| %2d |%s", i, line);
		else
			trigger = 0;
		free(line);
		i++;
	}
	printf("\n\033[36;01m| ^^ | le texte prend fin a la ligne du dessus en blanc | ^^ |\033[00m\n");
	return (0);
}
