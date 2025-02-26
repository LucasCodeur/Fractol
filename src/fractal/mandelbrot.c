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
	t_mlx	*data;

	data = (t_mlx *)param;
	(void)x;
	(void)y;
	if (!data)
	{
		free_img(data);
		return (1);
	}
	if (button == 4 && data->scale < MAX_SCALE)
		data->scale /= 1.1;
	if (button == 5 && data->scale > MIN_SCALE)
		data->scale *= 1.1;
	mandelbrot(data);
	return (0);
}

void	hook_mandelbrot(t_mlx data)
{
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_hook(data.mlx_win, 4, 1L << 2, mouse_hook_mandelbrot, &data);
	mlx_loop(data.mlx);
	free_img(&data);
}

static void	map_to_complex(t_mlx *data, double *re, double *im)
{
	*re = MIN_RE_M + ((double)data->coord.x / (double)MAX_WIDTH) * (MAX_RE_M
			- MIN_RE_M);
	*im = MAX_IM_M - ((double)data->coord.y / (double)MAX_HEIGHT) * (MAX_IM_M
			- MIN_IM_M);
	*re *= data->scale;
	*im *= data->scale;
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

void	mandelbrot(t_mlx *data)
{
	size_t	i;

	data->coord.y = 0;
	while (data->coord.y < MAX_HEIGHT)
	{
		data->coord.x = 0;
		while (data->coord.x < MAX_WIDTH)
		{
			map_to_complex(data, &data->c.r, &data->c.i);
			i = 0;
			mandelbrot_formula(data->c, &i);
			if (i == MAX_ITER)
				my_mlx_pixel_put(&data->img, data->coord.x, data->coord.y,
					BLACK);
			else
				my_mlx_pixel_put(&data->img, data->coord.x, data->coord.y,
					get_color(i));
			data->coord.x++;
		}
		data->coord.y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
}
