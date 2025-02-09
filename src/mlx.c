/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:10 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/08 17:14:57 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	free_img(t_mlx *t_mlx)
{
	if (t_mlx->img.img)
		mlx_destroy_image(t_mlx->mlx, t_mlx->img.img);
	if (t_mlx->mlx_win)
		mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
	if (t_mlx->mlx)
	{
		mlx_destroy_display(t_mlx->mlx);
		free(t_mlx->mlx);
	}
}

void	init_screen_mlx(t_mlx *t_mlx)
{
	t_mlx->mlx = mlx_init();
	if (!t_mlx->mlx)
		return ;
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, MAX_WIDTH, MAX_HEIGHT, "Fractol");
	if (!t_mlx->mlx_win)
		return ;
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img, &(t_mlx->img.bits_per_pixel), &(t_mlx->img.line_length),
									 &(t_mlx->img.endian));
	if (!t_mlx->img.addr)
		return ;
}

void make_complex_plan(t_mlx *window)
{
	double x;
	double y;
	int		screen_x;
	int		screen_y;

	x = 0.0;
	y = 0.0;
	screen_x = (int)(x * SCALE + MAX_WIDTH / 2);
	screen_y = (int)(-y * SCALE + MAX_HEIGHT / 2);
	if (screen_x >= 0 && screen_x < MAX_WIDTH && screen_y >= 0 && screen_y < MAX_HEIGHT)
		my_mlx_pixel_put(&(window->img), screen_x, screen_y, 0xFFFFFF);
	mlx_put_image_to_window(window->mlx, window->mlx_win, window->img.img, 0, 0);
}

