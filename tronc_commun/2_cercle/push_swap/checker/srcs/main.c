/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/02/27 17:40:41 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		trigger;

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
