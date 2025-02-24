/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:55:27 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 17:31:27 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

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

void	ft_hook(t_mlx window)
{
	mlx_hook(window.mlx_win, 2, 1L<<0, key_press, &window);
    mlx_hook(window.mlx_win, 17, 0, close_win, &window);
    mlx_hook(window.mlx_win, 4, 1L<<2, mouse_hook, &window);
    mlx_loop(window.mlx);
    free_img(&window);
}
