/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/22 04:40:54 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "libft/includes/libft.h"

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		v;
	int		c;
}			t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_point	***map;
}			t_fdf;

//		end.c			//
void		ft_exit(char *erreur);
void		ft_error(char *one_line, char **map_2d, t_fdf *info, char *message);

//		get_info.c		//
char		*ft_get_one_line(int fd);
t_fdf		*ft_make_info(char *filename);
t_fdf		*ft_get_info(char *filename);

//		init.c			//
t_point		***ft_make_map(int width, int height, char **map_2d);

//		verif.c			//
int			ft_verif_extention(char *filename, char *exe);

#endif
