/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/05 08:29:56 by gmarquis         ###   ########.fr       */
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

# include <X11/keysym.h>
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

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
	t_img	img;
}			t_fdf;

//		end.c			//
void		ft_free_map(t_fdf *info);
void		ft_free_info(t_fdf *info);
void		ft_exit(int out, char *message);
void		ft_free_and_out(t_fdf *info, int flag, int out, char *message);

//		get_info.c		//
int			ft_get_color(char *str);
void		ft_get_one_line(t_fdf *info);
void		ft_get_info(char *filename, t_fdf *info);

//		init.c			//
void		ft_init_window(t_fdf *info);
t_point		ft_new_point(int x, int y, char *str);
void		ft_make_map(t_fdf *info);
void		ft_new_fdf(t_fdf *info);

//		input.c			//
int			ft_handle_input(int keysym, t_fdf *info);

//		verif.c			//
int			ft_verif_cordo(char *str);
void		ft_verif_extention(char *filename, char *exe);

#endif
