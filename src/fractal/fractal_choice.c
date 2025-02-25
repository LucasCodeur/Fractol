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
    long double	check_double_overflow;
    long double	check_double_overflow_2;

    check_double_overflow = ft_atod(str[2]); 
    check_double_overflow_2 = ft_atod(str[3]); 
    if (check_double_overflow > DBL_MAX || check_double_overflow_2 > DBL_MAX)
    {
	free_img(win);
	error_message();
	exit(EXIT_FAILURE);
    }
    (win)->c.r = (double)check_double_overflow;
    (win)->c.i = (double)check_double_overflow_2;
    return ;
}

void	fractal_choice(char **str, t_mlx *win)
{
    if (ft_strncmp(str[1], "Mandelbrot", ft_strlen_improve("Mandelbrot", '\0')) == 0)
    {
	mandelbrot(win);
	hook_mandelbrot(*win);
    }
    else if (ft_strncmp(str[1], "Julia", ft_strlen_improve("Julia", ' ')) == 0)
    {
	get_julia_value(win, str);
	julia(win);
	hook_julia(*win);
    }
    free_img(win);
    error_message();
    exit(EXIT_FAILURE);
 }
