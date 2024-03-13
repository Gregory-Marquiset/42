/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/13 12:11:32 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;
	int		trigger;

	fd = open("txt/waterloo.txt", O_RDONLY);
	i = 0;
	trigger = 1;
	printf("\033[36;01m| vv | le texte demarre a la ligne d'en dessou en blanc | vv |\033[00m\n");
	while (trigger == 1)
	{
		line = get_next_line(fd);
		printf("\033[36;01m| %2d |\033[00m%s\033[36;01m|\033[00m\n", i, line);
		if (line == NULL)
			trigger = 0;
		free(line);
		i++;
	}
	printf("\033[36;01m| ^^ | le texte prend fin a la ligne du dessus en blanc | ^^ |\033[00m\n");
	return (0);
}

// bora_vocal.txt = 42
// de_lamartine_1848 = 11
// poeme_sur_la_7eme.txt = 38
// 1char.txt = 1
// waterloo.txt = 10
// le_manuel.txt = 715
