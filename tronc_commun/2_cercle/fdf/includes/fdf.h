/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/26 20:50:34 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef C_BASE
#  define C_BASE 16777215
# endif

# include "libft/includes/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	v;
	int	c;
}			t_point;

typedef struct s_fdf
{
	int		fd;
	char	*one_line;
	char	**map_2d;
	int		width;
	int		height;
	t_point	**map;
	char	**erreur;
}			t_fdf;

//		end.c			//
void		ft_free_map(t_point **map);
void		ft_exit(char *erreur);
void		ft_error(t_fdf *info, char *message);

//		get_info.c		//
char		*ft_get_color(char *str);
void		ft_get_one_line(t_fdf *info);
void		ft_get_info(char *filename, t_fdf *info);

//		init.c			//
t_point		ft_new_point(int x, int y, char *str);
void		ft_make_map(t_fdf *info);
void		ft_new_fdf(t_fdf *info);

//		verif.c			//
int			ft_verif_cordo(char *str);
int			ft_verif_extention(char *filename, char *exe);

#endif
