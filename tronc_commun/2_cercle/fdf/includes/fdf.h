/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 15:51:57 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600
# define MENU_WIDTH 100
# define WINDOW_TITLE "Projet_FdF"
# define FACTOR 10

# include "color.h"
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "struct.h"
# include <X11/keysym.h>
# include <math.h>
# include <signal.h>

//		draw.c		//
void	ft_draw_map(t_fdf *fdf);

//		end.c			//
void	ft_free_map(t_fdf *info);
void	ft_free_info(t_fdf *info);
void	ft_free_and_out(t_fdf *info, int flag, int out, char *message);

//		get_info.c		//
int		ft_get_color(char *str);
void	ft_get_one_line(t_fdf *info);
void	ft_get_info(char *filename, t_fdf *info);

//		init.c			//
void	ft_init_iso(t_fdf *info);
void	ft_init_window(t_fdf *info);
t_point	ft_new_point(int x, int y, char *str);
void	ft_make_map(t_fdf *info);
void	ft_new_fdf(t_fdf *info);

//		input.c			//
int		ft_handle_cross(t_fdf *info);
int		ft_handle_input(int keysym, t_fdf *info);

//		keys_events.c	//
void	ft_move_events(int keysym, t_fdf *info);
void	ft_zoom_events(int keysym, t_fdf *info);
void	ft_rotate_events(int keysym, t_fdf *info);
void	ft_z_events(int keysym, t_fdf *info);
void	ft_reset_events(t_fdf *info);

//		verif.c			//
void	ft_verif_in_window(t_fdf *info, int y, int x);
int		ft_verif_cordo(char *str);

#endif
