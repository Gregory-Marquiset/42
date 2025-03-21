/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:48:55 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/23 00:07:38 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# define WINDOW_WIDTH 2000
# define WINDOW_HEIGHT 2000
# define WINDOW_TITLE "Projet_FdF"
# define FACTOR 10

# include "color.h"
# include "libft/includes/libft.h"
# include "minilibx-linux/mlx.h"
# include "struct.h"
# include <X11/keysym.h>
# include <math.h>
# include <signal.h>

//		coordo.c	//
void	ft_coordo_para(t_fdf *info, int y, int x);
void	ft_coordo_iso(t_fdf *info, int y, int x);

//		draw.c		//
void	ft_draw_map(t_fdf *fdf);

//		end.c			//
void	ft_free_map(t_fdf *info);
void	ft_free_info(t_fdf *info);
void	ft_free_and_out(t_fdf *info, int flag, int out, char *message);

//		get_info.c		//
void	ft_get_zoom(t_fdf *info);
int		ft_get_color(char *str);
void	ft_get_one_line(t_fdf *info);
void	ft_get_info(char *filename, t_fdf *info);
void	ft_get_map(t_fdf *info);

//		gradient.c		//
void	ft_get_grad(t_fdf *info);
void	ft_init_grad(t_fdf *info);

//		init.c			//
void	ft_init_drawl(t_fdf *info, int y, int x, int flag);
void	ft_init_modif_view(t_fdf *info);
void	ft_init_window(t_fdf *info);
t_point	ft_init_point(int x, int y, char *str);
void	ft_init_fdf(t_fdf *info);

//		input.c			//
int		ft_handle_cross(t_fdf *info);
void	ft_view_events(int keysym, t_fdf *info);
void	ft_change_color(int color, int color_d, int color_i, t_fdf *info);
void	ft_colors_events(int keysym, t_fdf *info);
int		ft_handle_input(int keysym, t_fdf *info);

//		keys_events.c	//
void	ft_move_events(int keysym, t_fdf *info);
void	ft_zoom_events(int keysym, t_fdf *info);
void	ft_rotate_events(int keysym, t_fdf *info);
void	ft_reset_events(int keysym, t_fdf *info);

//		pixel_color.c	//
void	ft_pixel_put(t_fdf *info, int x, int y, int color);

//		verif.c			//
int		ft_verif_cordo(char *str);
void	ft_verif_h(t_fdf *info);

//		z_events.c		//
void	ft_flat_event(t_fdf *info);
void	ft_hoist_event(t_fdf *info);
void	ft_z_events(int keysym, t_fdf *info);

#endif
