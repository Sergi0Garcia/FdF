/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:44 by segarcia          #+#    #+#             */
/*   Updated: 2022/10/19 11:18:38 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./minilibx_macos/mlx.h"
# include "./ft_libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**hex_color;
	int		color;
	int		is_blur;
	float	z_mult;
	int		shift_x;
	int		shift_y;
	float	rotation_x;
	float	rotation_y;
	float	rotation_z;
	int		zoom;
	int		win_x;
	int		win_y;
	int		is_isometric;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

typedef struct s_line
{
	float	x_step;
	float	y_step;
	float	max;
	int		is_slope;
	int		i_slope;
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	z;
	float	z1;
}	t_line;

float	f_max(float a, float b);
void	line_setter(t_line *l, t_fdf *d, char increment);
void	line_validation(t_fdf *d, t_line *l);
void	draw(t_fdf *d);
void	fd_validation(int fd, t_fdf *d);
void	argc_validation(int argc);
void	map_format_error(void);
void	malloc_error(t_fdf *d);
void	mlx_error(void);
int		key_handler(int key, t_fdf *d);
int		handle_win_size(int key, t_fdf *d);
void	fdf_print_menu(t_fdf *d);
void	ft_handle_2d(t_line *l, t_fdf *d);
void	ft_handle_3d(t_line *l, t_fdf *d);
void	rotation_xyz(float *x, float *y, float *z, t_fdf *d);
int		get_height(char *filename);
int		get_width(char *filename, int height);
void	free_with_i(int i, t_fdf *d, int err);
void	allocate_matrixes(t_fdf *d);
void	allocate_imatrix(t_fdf *d, int i);
void	read_map(char *filename, t_fdf *d);
int		ft_hex_to_int(char *hex);
int		is_valid_hex_format(char *str);
void	set_opposite(int val, int *var);
int		close_win(t_fdf *d);
void	free_all(t_fdf *d);
#endif