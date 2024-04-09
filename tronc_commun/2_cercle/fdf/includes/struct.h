/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:12:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/09 08:27:17 by gmarquis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	les delta indique les écarts entre les coordonnées x et y
//	les step indique les pas dans chaque direction

typedef struct s_drawl
{
	double	x_start;
	double	y_start;
	double	z_start;
	double	x_end;
	double	y_end;
	double	z_end;
	double	delta_x;
	double	delta_y;
	double	delta_z;
	double	step_x;
	double	step_y;
	double	step_z;
	double	error;
	double	error2;
}			t_drawl;

typedef struct s_iso
{
	double		iso_x;
	double		iso_y;
	double		dpl_x;
	double		dpl_y;
	double		tmp_x;
	double		tmp_y;
	double		rotation_x;
	double		rotation_y;
	double		rotation_z;
	double		rotated_y_x;
	double		rotated_z_x;
	double		rotated_x_y;
	double		rotated_x_z;
	double		rotated_y_z;
}			t_iso;

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
	double		x;
	double		y;
	double		z;
	double		x_ori;
	double		y_ori;
	double		z_ori;
	int			v;
	int			c;
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
	t_iso	iso;
	t_img	img;
	double	zoom;
	t_drawl	drawl;
}			t_fdf;
