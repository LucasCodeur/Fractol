/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:55:27 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/18 20:37:49 by lud-adam         ###   ########.fr       */
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

int	mouse_hook(int button, t_mlx *win)
{
	if (!win)
		return (1);
	if (button == 4 && win->scale < MAX_SCALE)
		ZOOM_IN(win->scale);
	if (button == 5 && win->scale < MIN_SCALE)
		ZOOM_OUT(win->scale);
	mandelbrot(win);
	return (0);
}
