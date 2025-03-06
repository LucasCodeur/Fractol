/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:53:18 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/21 19:40:50 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mouse_hook_julia(int button, int x, int y, void *param)
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
	julia(data);
	return (0);
}

void	hook_julia(t_mlx data)
{
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 17, 0, close_win, &data);
	mlx_hook(data.mlx_win, 4, 1L << 2, mouse_hook_julia, &data);
	mlx_loop(data.mlx);
	free_img(&data);
}

static void	julia_formula(t_cn c, size_t *i, t_cn z)
{
	t_cn	temp;

	temp.r = 0;
	while (z.r * z.r + z.i * z.i <= 4 && *i < MAX_ITER)
	{
		temp.r = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * temp.r + c.i;
		(*i)++;
	}
}

void	julia(t_mlx *data)
{
	size_t	i;

	data->coord.y = 0;
	while (data->coord.y < HEIGHT)
	{
		data->coord.x = 0;
		while (data->coord.x < WIDTH)
		{
			i = 0;
			data->z.r = (MIN_RE_J + data->coord.x * (MAX_RE_J - MIN_RE_J)
					/ ((double)WIDTH)) * data->scale;
			data->z.i = (MAX_IM_J - data->coord.y * (MAX_IM_J - MIN_IM_J)
					/ ((double)HEIGHT)) * data->scale;
			julia_formula(data->c, &i, data->z);
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
