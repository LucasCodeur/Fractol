/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_choice.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:13:22 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/03 16:44:50 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fractol.h"

static void	get_julia_value(t_mlx *data, char **str)
{
	long double	check_double_overflow;
	long double	check_double_overflow_2;

	check_double_overflow = ft_atod(str[2]);
	check_double_overflow_2 = ft_atod(str[3]);
	if ((check_double_overflow > MAX_DOUBLE
			|| check_double_overflow_2 > MAX_DOUBLE)
		&& (check_double_overflow < MIN_DOUBLE
			|| check_double_overflow_2 < MIN_DOUBLE))
	{
		free_img(data);
		error_message();
		exit(EXIT_FAILURE);
	}
	(data)->c.r = (double)check_double_overflow;
	(data)->c.i = (double)check_double_overflow_2;
	return ;
}

void	fractal_choice(int argc, char **str, t_mlx *data)
{
	size_t	size_mandelbrot;
	size_t	size_julia;

	size_mandelbrot = ft_strlen("Mandelbrot");
	size_julia = ft_strlen("Julia");
	if (ft_strncmp(str[1], "Mandelbrot", size_mandelbrot) == 0 && argc == 2)
	{
		mandelbrot(data);
		hook_mandelbrot(*data);
	}
	else if (ft_strncmp(str[1], "Julia", size_julia) == 0 && argc == 4)
	{
		get_julia_value(data, str);
		julia(data);
		hook_julia(*data);
	}
	free_img(data);
	error_message();
	exit(EXIT_FAILURE);
}
