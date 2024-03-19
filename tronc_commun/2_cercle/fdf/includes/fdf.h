/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/19 05:59:25 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_map
{
	int		x;
	int		y;
	int		z;
	int		v;
}			t_map;

typedef struct s_fdf
{
	int		fd;
	char	*one_line;
	int		width;
	int		height;
	t_map	***map;
}			t_fdf;

//		end.c			//
void		ft_free_info(t_fdf **info);
void		ft_error(t_fdf **info);

//		get_info.c		//
void		ft_get_l_w_h(t_fdf **info);
void		ft_get_info(char *filename, t_fdf **info);

//		init.c			//
t_map		*ft_new_point(int y, int x, char *str);
t_fdf		*ft_new_fdf(void);
void		ft_make_map(t_fdf **info, char	*line_tmp);

# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

#endif
