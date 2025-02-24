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

static void julia_formula(t_cn c, size_t *i, t_cn z)
{
    t_cn temp;

    temp.r = 0;
    while (z.r * z.r + z.i * z.i < 4 && *i < MAX_ITER)
    {
        temp.r = z.r;
        z.r = z.r * z.r - z.i * z.i + c.r;
        z.i = 2 * z.i * temp.r + c.i;
        (*i)++;
    }
}

void	julia(t_mlx *win, t_cn c)
{
	t_coord coord;
	t_cn	z;
	size_t	i;

	coord.y = 0;
	while (coord.y < MAX_HEIGHT)
	{
		coord.x = 0;
		while (coord.x < MAX_WIDTH)
		{
			i = 0;
			z.r = MIN_RE_J + coord.x * (MAX_RE_J - MIN_RE_J) / (MAX_WIDTH - 1);
			z.i = MAX_IM_J - coord.y * (MAX_IM_J - MIN_IM_J) / (MAX_HEIGHT - 1);
			julia_formula(c, &i, z);
			if (i == MAX_ITER)
				my_mlx_pixel_put(&win->img, coord.x, coord.y, BLACK);
			else
				my_mlx_pixel_put(&win->img, coord.x, coord.y, get_color(i));
			coord.x++;
		}
		coord.y++;
	}
	mlx_put_image_to_window(win->mlx, win->mlx_win, win->img.img, 0, 0);
}
