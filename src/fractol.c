/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:46:22 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/08 16:34:52 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_mlx *window)
{
	t_coord	coord;
	int		i;
	int		tmp;

	coord.c_r = coord.x;
	coord.c_i = coord.y;
	coord.z_r = 0;
	coord.z_i = 0;
	i = 0;
	tmp = coord.z_r;
	coord.z_r = coord.z_r*coord.z_r - coord.z_i*coord.z_i + coord.c_r;
	coord.z_i = 2*coord.z_i*tmp + coord.c_i;
	i = i + 1;
	while (coord.z_r*coord.z_r + coord.z_i*coord.z_i < 4 && i < MAX_ITER)
	{
		if (i == MAX_ITER)
			my_mlx_pixel_put(&window->img, coord.c_r, coord.c_i, 0X000000);
	}
}
