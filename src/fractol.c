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

void map_to_complex(int x, int y, double *Re, double *Im)
{
    *Re = MIN_RE + (x / (double)MAX_WIDTH) * (MAX_RE - MIN_RE);
    *Im = MAX_IM - (y / (double)MAX_HEIGHT) * (MAX_IM - MIN_IM);
}

int get_color(int i)
{
	if (i == MAX_ITER)
		return 0x000000; 
	int r; 
	int g;
	int b;

	r = (i * 9) % 256;
	g = (i * 2) % 256;
	b = (i * 4) % 256;
	return (r << 16) | (g << 8) | b;
}

void	mandelbrot(t_mlx *window)
{
	t_coord	coord;
	t_cn	c;
	t_cn	z;
	t_cn	temp;
	size_t	i;
	double	Re;
	double	Im;

	coord.y = 0;
	while (coord.y < MAX_HEIGHT)
	{
		coord.x = 0;
		while (coord.x < MAX_WIDTH)
		{	
			map_to_complex(coord.x, coord.y, &Re, &Im);
			c.r = Re;
			c.i = Im;
			z.r = 0;
			z.i = 0;
			i = 0;
			while (z.r * z.r + z.i * z.i < 4 && i < MAX_ITER)
			{
				temp.r = z.r;
				z.r = z.r * z.r - z.i * z.i + c.r;
				z.i = 2 * z.i * temp.r + c.i;
				i++;
			}
			if (i == MAX_ITER)
				my_mlx_pixel_put(&window->img, coord.x, coord.y, BLACK);
			else
				my_mlx_pixel_put(&window->img, coord.x, coord.y, get_color(i));
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img.img, 0, 0);
}
