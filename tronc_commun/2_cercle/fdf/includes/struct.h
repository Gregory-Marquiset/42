/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarquis <gmarquis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 12:12:37 by gmarquis          #+#    #+#             */
/*   Updated: 2024/04/10 22:04:01 by gmarquis         ###   ########.fr       */
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
	double		rotated_y;
	double		rotated_z;
	double		rotated_x;
}			t_iso;

typedef struct s_modif
{
	int			active_para;
	int			active_iso;
	int			colors_modif;
	double		zoom;
	double		dpl_x;
	double		dpl_y;
	double		tmp_x;
	double		tmp_y;
	double		tmp_z;
	double		rotation_x;
	double		rotation_y;
	double		rotation_z;
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
	double		x;
	double		y;
	double		z;
	int			c;
	double		x_ori;
	double		y_ori;
	double		z_ori;
	int			c_ori;
	int			v;
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
	t_modif	modif;
	t_iso	iso;
	t_img	img;
	t_drawl	drawl;
}			t_fdf;
