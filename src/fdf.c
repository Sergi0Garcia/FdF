/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segarcia <segarcia@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 11:19:02 by segarcia          #+#    #+#             */
/*   Updated: 2022/09/22 11:45:12 by segarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_default(t_fdf *d)
{
	d->z_mult = 1;
	d->rotation_x = 0.0;
	d->rotation_y = 0.0;
	d->rotation_z = 0.0;
	d->zoom = 10;
	d->is_blur = 0;
	d->win_x = 2560;
	d->win_y = 1400;
	d->is_isometric = 0;
	d->shift_x = d->win_x / 2;
	d->shift_y = d->win_y / 3;
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, d->win_x, d->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	argc_validation(argc);
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		malloc_error(data);
	set_default(data);
	read_map(argv[1], data);
	draw(data);
	mlx_hook(data->win_ptr, 17, 1, close_win, data);
	mlx_key_hook(data->win_ptr, key_handler, data);
	mlx_loop(data->mlx_ptr);
}
