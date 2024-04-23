/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 04:56:48 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 14:42:35 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

// static void	ft_print_line_modif(t_gnl *gnl)
// {
// 	int		until;

// 	if (!gnl->tempo)
// 		return (NULL);
// 	until = ft_countuntil(gnl->tempo, gnl->n);
// 	ft_strlcpy(gnl->l_to_print, gnl->tempo, until);
// 	*gnl->static_l[gnl->fd] = ft_memlcpy(gnl->tempo, until);
// }

static void	ft_verif_and_init_gnl(int fd, char n, t_gnl *gnl)
{
	gnl->fd = fd;
	gnl->n = n;
	if (gnl->fd < 0)
		ft_exit(2, "Error : failure to open fd.\n");
	if (BUFFER_SIZE < 1)
		ft_exit(2, "Error : failure BUFFER_SIZE smaller than 1.\n");
	if (read(gnl->fd, 0, 0) < 0)
		ft_exit(2, "Error : read failure.\n");
	gnl->static_l[gnl->fd][0] = '1';
	gnl->static_l[gnl->fd][1] = '2';
	gnl->static_l[gnl->fd][2] = '3';
	gnl->static_l[gnl->fd][3] = '\n';
	gnl->static_l[gnl->fd][4] = '5';
	gnl->tempo = gnl->static_l[gnl->fd];
	gnl->o_read = 1;
	gnl->l_to_print[0] = 'O';
	gnl->l_to_print[1] = 'K';
	gnl->l_to_print[2] = '.';
	gnl->l_to_print[3] = '\0';
}

char	*get_next_line_modif(int fd, char n)
{
	static t_gnl	gnl;

	ft_verif_and_init_gnl(fd, n, &gnl);
	if (ft_contain_n(gnl.static_l[fd], n))
	{
//		ft_print_line_modif(&gnl);
		return (gnl.l_to_print);
	}
	// if (gnl.static_l[fd])
	// 	gnl.tempo = ft_strdup(gnl.static_l[fd]);
	// else
	// 	gnl.tempo = ft_calloc(0, 0);
	// while (o_read > 0)
	// {
	// 	o_read = read(fd, buffer, BUFFER_SIZE);
	// 	buffer[o_read] = '\0';
	// 	tempo = ft_strjoin(tempo, buffer, 1);
	// 	if (ft_contain_n(tempo, n))
	// 		break ;
	// }
	ft_printf("tempo = |%s|\nstatic = |%s|\n", gnl.tempo, gnl.static_l[gnl.fd]);
	return (0);
	// return (ft_print_line_modif(&stat[fd], tempo, n));
}
