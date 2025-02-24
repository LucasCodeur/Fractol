/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 09:57:11 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 09:58:39 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

int	mouse_hook(int button, int x, int y, void *param)
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
