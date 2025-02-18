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

void	free_img(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img.img)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx->img.img = NULL;
	}
	if (mlx->mlx_win)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		mlx->mlx_win = NULL;
	}
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		mlx->mlx = NULL;
	}
}

void	init_screen_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		ft_printf("Error : mlx_init failed\n");
		return ;
	}
	mlx->mlx_win = mlx_new_window(mlx->mlx, MAX_WIDTH, MAX_HEIGHT, "Fractol");
	if (!mlx->mlx_win)
	{
		ft_printf("Error: mlx_new_window failed\n");
		free_img(mlx);
		return ;
	}
	mlx->img.img = mlx_new_image(mlx->mlx, MAX_WIDTH, MAX_HEIGHT);
	if (!mlx->img.img)
	{
	        ft_printf("Error: mlx_new_image failed\n");
		free_img(mlx);
		return ;
	}
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, &mlx->img.line_length,
									 &mlx->img.endian);
	if (!mlx->img.addr)
	{
	        ft_printf("Error: mlx_get_data_addr failed\n");
		free_img(mlx);
		return ;
	}
	mlx->scale = 1.0;
}

