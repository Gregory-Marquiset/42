/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 20:26:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*info;
	char	**str;
	int		count;
	int		i;

	if (argc != 2)
		return (0);
	info = ft_get_info(argv[1]);
	ft_printf("one_line :\n%sWidth = %d\nHeight = %d\nmap :\n", info->one_line, info->width, info->height);
	ft_free_info(&info);
	return (0);
}
