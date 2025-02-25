/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:46:22 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/21 19:14:57 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	mouse_hook_mandelbrot(int button, int x, int y, void *param)
{
	t_mlx	*win;

	win = (t_mlx *)param;
	(void)x;
	(void)y;
	if (!win)
	{
		free_img(win);
		return (1);
	}
	if (button == 4 && win->scale < MAX_SCALE)
		ZOOM_OUT(win->scale);
	if (button == 5 && win->scale > MIN_SCALE)
		ZOOM_IN(win->scale);
	mandelbrot(win);
	return (0);
}

void	hook_mandelbrot(t_mlx window)
{
	mlx_hook(window.mlx_win, 2, 1L << 0, key_press, &window);
	mlx_hook(window.mlx_win, 17, 0, close_win, &window);
	mlx_hook(window.mlx_win, 4, 1L << 2, mouse_hook_mandelbrot, &window);
	mlx_loop(window.mlx);
	free_img(&window);
}

static void	map_to_complex(t_mlx *win, double *re, double *im)
{
	*re = MIN_RE_M + ((double)win->coord.x / (double)MAX_WIDTH) * (MAX_RE_M
			- MIN_RE_M);
	*im = MAX_IM_M - ((double)win->coord.y / (double)MAX_HEIGHT) * (MAX_IM_M
			- MIN_IM_M);
	*re *= win->scale;
	*im *= win->scale;
}

static void	mandelbrot_formula(t_cn c, size_t *i)
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

	win->coord.y = 0;
	while (coord.y < MAX_HEIGHT)
	{
		win->coord.x = 0;
		while (win->coord.x < MAX_WIDTH)
		{
			map_to_complex(win, &c.r, &c.i);
			i = 0;
			mandelbrot_formula(c, &i);
			if (i == MAX_ITER)
				my_mlx_pixel_put(&win->img, win->coord.x, win->coord.y, BLACK);
			else
				my_mlx_pixel_put(&win->img, win->coord.x, win->coord.y,
					get_color(i));
			win->coord.x++;
		}
		win->coord.y++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
}
