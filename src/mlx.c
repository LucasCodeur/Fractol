/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:01:10 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/17 19:10:02 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= MAX_WIDTH  || y < 0 || y >= MAX_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	free_img(t_mlx *t_mlx)
{
	if (!t_mlx)
		return ;
	if (t_mlx->img.img)
	{
		mlx_destroy_image(t_mlx->mlx, t_mlx->img.img);
		t_mlx->img.img = NULL;
	}
	if (t_mlx->mlx_win)
	{
		mlx_destroy_window(t_mlx->mlx, t_mlx->mlx_win);
		t_mlx->mlx_win = NULL;
	}
	if (t_mlx->mlx)
	{
		mlx_destroy_display(t_mlx->mlx);
		t_mlx->mlx = NULL;
	}
}

int	key_press(int keycode, void *param)
{
	if (!param)
		return (0);
	t_mlx *mlx = (t_mlx *)param;
	if (keycode == 65307)
	{
		free_img(mlx);
		exit(0);
	}
	return (0);
}

int	close_win(void *param)
{
	if (!param)
		return (0);
	t_mlx *win = (t_mlx *)param;
	free_img(win);
	exit(0);
}

void	init_screen_mlx(t_mlx *t_mlx)
{
	t_mlx->mlx = mlx_init();
	if (!t_mlx->mlx)
	{
		ft_printf("Error : mlx_init failed\n");
		return ;
	}
	t_mlx->mlx_win = mlx_new_window(t_mlx->mlx, MAX_WIDTH, MAX_HEIGHT, "Fractol");
	if (!t_mlx->mlx_win)
	{
		ft_printf("Error: mlx_new_window failed\n");
		free_img(t_mlx);
		return ;
	}
	t_mlx->img.img = mlx_new_image(t_mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	if (!t_mlx->img.img)
	{
	        ft_printf("Error: mlx_new_image failed\n");
		free_img(t_mlx);
		return ;
	}
	t_mlx->img.addr = mlx_get_data_addr(t_mlx->img.img, &t_mlx->img.bits_per_pixel, &t_mlx->img.line_length,
									 &t_mlx->img.endian);
	if (!t_mlx->img.addr)
	{
	        ft_printf("Error: mlx_get_data_addr failed\n");
		free_img(t_mlx);
		return ;
	}
}

