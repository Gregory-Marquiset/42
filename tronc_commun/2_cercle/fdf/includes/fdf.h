/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/03/29 06:03:53 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define WINDOW_TITLE "Projet_FdF"

# ifndef C_BASE
#  define C_BASE 16777215
# endif

# include "keys.h"
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"

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
	int		fd;
	char	*one_line;
	int		height;
	int		width;
	char	**map_2d;
	t_point	**map;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

//		end.c			//
void		ft_free_map(t_fdf *info);
void		ft_free_info(t_fdf *info);
void		ft_exit(char *error);
void		ft_error(t_fdf *info, int flag, char *message);

//		get_info.c		//
int			ft_get_color(char *str);
void		ft_get_one_line(t_fdf *info);
void		ft_get_info(char *filename, t_fdf *info);

//		init.c			//
int			ft_key_press(int keycode, t_fdf *info);
void		ft_set_key_hook(t_fdf *info);
void		ft_init_window(t_fdf *info);
t_point		ft_new_point(int x, int y, char *str);
void		ft_make_map(t_fdf *info);
void		ft_new_fdf(t_fdf *info);

//		verif.c			//
int			ft_verif_cordo(char *str);
void		ft_verif_extention(char *filename, char *exe);

#endif
