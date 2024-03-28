/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:09:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/28 15:15:14 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	info;

	if (argc != 2)
		return (ft_exit("Erreur : mauvais format d'argument (./fdf map)"), 0);
	ft_get_info(argv[1], &info);
	ft_free_info(&info);
	return (0);
}
