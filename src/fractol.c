/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:46:22 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/17 14:41:09 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	map_to_complex(int x, int y, double *re, double *im)
{
	*re = MIN_RE + ((double)x / (double)MAX_WIDTH) * (MAX_RE - MIN_RE);
	*im = MAX_IM - ((double)y / (double)MAX_HEIGHT) * (MAX_IM - MIN_IM);
}

int	get_color(int i)
{
	int	r;
	int	g;
	int	b;

	if (i == MAX_ITER)
		return (0x000000);
	r = (i * 9) % 256;
	g = (i * 2) % 256;
	b = (i * 4) % 256;
	return ((r << 16) | (g << 8) | b);
}

void	mandelbrot_formula(t_cn c, size_t *i)
{
	t_cn	z;
	t_cn	temp;

	z.r = 0;
	z.i = 0;
	temp.r = 0;
	while (z.r * z.r + z.i * z.i < 4 && *i < MAX_ITER)
	{
		temp.r = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * temp.r + c.i;
		(*i)++;
	}
}

void	mandelbrot(t_mlx *win)
{
	t_coord	coord;
	t_cn	c;
	size_t	i;

	coord.y = 0;
	while (coord.y < MAX_HEIGHT)
	{
		coord.x = 0;
		while (coord.x < MAX_WIDTH)
		{
			map_to_complex(coord.x, coord.y, &c.r, &c.i);
			i = 0;
			mandelbrot_formula(c, &i);
			if (i == MAX_ITER)
				my_mlx_pixel_put(&win->img, coord.x, coord.y, BLACK);
			else
				my_mlx_pixel_put(&win->img, coord.x, coord.y, get_color(i));
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
}
