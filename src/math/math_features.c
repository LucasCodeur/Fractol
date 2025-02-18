/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_features.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:40:47 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/18 20:32:13 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

void	map_to_complex(int x, int y, double *re, double *im, t_mlx *win)
{
	*re = MIN_RE + ((double)x / (double)MAX_WIDTH) * (MAX_RE - MIN_RE) + win->scale;
	*im = MAX_IM - ((double)y / (double)MAX_HEIGHT) * (MAX_IM - MIN_IM) + win->scale;
}
