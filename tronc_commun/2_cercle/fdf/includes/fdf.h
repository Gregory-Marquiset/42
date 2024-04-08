/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/08 09:34:52 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define MENU_WIDTH 100
# define WINDOW_TITLE "Projet_FdF"
# define ANGLE_INCREMENT 0.1

# include "color.h"
# include "key_signals.h"
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "struct.h"
# include <math.h>

//		arrow_events.c	//
void	ft_arrow_event(int keysym, t_fdf *info);

//		draw.c		//
void	ft_draw_map(t_fdf *fdf);

//		end.c			//
void	ft_free_map(t_fdf *info);
void	ft_free_info(t_fdf *info);
void	ft_exit(int out, char *message);
void	ft_free_and_out(t_fdf *info, int flag, int out, char *message);

//		get_info.c		//
int		ft_get_color(char *str);
void	ft_get_one_line(t_fdf *info);
void	ft_get_info(char *filename, t_fdf *info);

//		init.c			//
void	ft_init_window(t_fdf *info);
t_point	ft_new_point(int x, int y, char *str);
void	ft_make_map(t_fdf *info);
void	ft_new_fdf(t_fdf *info);

//		input.c			//
void	my_pixel_put(t_img *img, int x, int y, int z, int color);
int		ft_handle_input(int keysym, t_fdf *info);

//		rotate_events.c	//
void	ft_rotate_event(int keysym, t_fdf *info);

//		verif.c			//
int		ft_verif_cordo(char *str);
void	ft_verif_extention(char *filename, char *exe);

//		zoom_events.c	//
void	ft_zoom_event(int keysym, t_fdf *info);

#endif
