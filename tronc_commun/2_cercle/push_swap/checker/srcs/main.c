/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:23:29 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/01 20:43:42 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**clean_input;

	i = 0;
	if (argc < 4)
		return (0);
	clean_input = ft_check_input(argv);
	if (clean_input == NULL)
		ft_error(NULL, NULL);
	while (clean_input[i])
	{
		ft_printf("%s\n", clean_input[i]);
		i++;
	}
	ft_le_xav(clean_input);
	return (0);
}
