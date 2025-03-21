/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:12:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/22 22:59:27 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	les delta indique les écarts entre les coordonnées x et y
//	les step indique les pas dans chaque direction

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_grad
{
	double	progress;
	int		delta_red;
	int		delta_green;
	int		delta_blue;
	int		intermediate_red;
	int		intermediate_green;
	int		intermediate_blue;
	int		intermediate_color;
}			t_grad;

typedef struct s_drawl
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		delta_x;
	int		delta_y;
	int		step_x;
	int		step_y;
	int		error;
	int		error2;
	int		c_start;
	int		c_end;
}			t_drawl;

typedef struct s_iso
{
	double	rotated_y;
	double	rotated_z;
	double	rotated_x;
}			t_iso;

typedef struct s_modif
{
	int		active_para;
	int		active_iso;
	int		colors_modif;
	double	zoom;
	double	dpl_x;
	double	dpl_y;
	double	dpl_z;
	double	tmp_x;
	double	tmp_y;
	double	tmp_z;
	double	rotation_x;
	double	rotation_y;
	double	rotation_z;
}			t_modif;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		c;
	double	x_ori;
	double	y_ori;
	double	z_ori;
	int		c_ori;
	int		v;
}			t_point;

typedef struct s_fdf
{
	int		w_width;
	int		w_height;
	int		factor;
	int		fd;
	char	*one_line;
	int		height;
	int		width;
	char	**map_2d;
	t_point	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	t_modif	modif;
	t_iso	iso;
	t_img	img;
	t_drawl	drawl;
	t_grad	grad;
}			t_fdf;

#endif
