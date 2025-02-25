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
	t_mlx	*mlx;

	if (!param)
		return (0);
	mlx = (t_mlx *)param;
	if (keycode == 65307)
	{
		free_img(mlx);
		exit(0);
	}
	return (0);
}

int	close_win(void *param)
{
	t_mlx	*win;

	if (!param)
		return (0);
	win = (t_mlx *)param;
	free_img(win);
	exit(0);
}
