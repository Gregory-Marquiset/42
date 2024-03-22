/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 02:23:59 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	*info;

	if (argc != 2)
		return (ft_exit("Erreur : mauvais format d'argument (./fdf map)"), 0);
	info = ft_get_info(argv[1]);
	//ft_printf("Width = %2d\nHeight = %2d\nmap :\n", info->width, info->height);
	//ft_free_info(&info);
	return (0);
}
