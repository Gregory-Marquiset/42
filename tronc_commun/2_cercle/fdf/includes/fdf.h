/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/20 21:20:29 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		v;
	struct s_point	*next;
}			t_point;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_point	*map;
}			t_fdf;

//		end.c			//
void		ft_free_info(t_fdf *info);
void		ft_error(t_fdf *info);

//		get_info.c		//
t_fdf		*ft_make_info(int fd);
t_fdf		*ft_get_info(char *filename);

//		init.c			//
t_point		*ft_new_point(int y, int x, char *str);
t_fdf		*ft_new_fdf(char **map_2d, char *one_line);
void		ft_make_map(t_fdf *info, char	*line_tmp);

# include "libft/includes/libft.h"

#endif
