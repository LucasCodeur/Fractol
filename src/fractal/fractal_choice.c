/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:13:22 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/25 11:20:33 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	get_julia_value(t_mlx *win, char **str)
{
	double		max_double;
	double		min_double;
	long double	check_double_overflow;
	long double	check_double_overflow_2;

	check_double_overflow = ft_atod(str[2]);
	check_double_overflow_2 = ft_atod(str[3]);
	max_double = (2.0 - (1.0 / (1LL << 52))) * pow(2.0, 1023);
	min_double = pow(2.0, -1022);
	if ((check_double_overflow > max_double || check_double_overflow_2 > max_double) || (check_double_overflow < min_double || check_double_overflow_2 < min_double))
	{
		free_img(win);
		error_message();
		exit(EXIT_FAILURE);
	}
	(win)->c.r = (double)check_double_overflow;
	(win)->c.i = (double)check_double_overflow_2;
	return ;
}

void	fractal_choice(int argc, char **str, t_mlx *win)
{
	size_t	size_mandelbrot;
	size_t	size_julia;

	size_mandelbrot = ft_strlen("Mandelbrot");
	size_julia = ft_strlen("Julia");
	if (ft_strncmp(str[1], "Mandelbrot", size_mandelbrot) == 0 && argc == 2)
	{
		mandelbrot(win);
		hook_mandelbrot(*win);
	}
	else if (ft_strncmp(str[1], "Julia", size_julia) == 0 && argc == 4)
	{
		get_julia_value(win, str);
		julia(win);
		hook_julia(*win);
	}
	free_img(win);
	error_message();
	exit(EXIT_FAILURE);
}
