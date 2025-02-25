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

static void	get_julia_value(t_cn *c, char **str, t_bool *error)
{
    long double	check_overflow;
    long double	check_overflow_2;

    check_overflow = ft_atod(str[2]); 
    check_overflow_2 = ft_atod(str[3]); 
    if (check_overflow > DBL_MAX || check_overflow_2 > DBL_MAX)
    {
	*error = TRUE;
	return ;
    }
    c->r = check_overflow;
    c->i = check_overflow_2;
    return ;
}

void	fractal_choice(char **str, t_mlx *win)
{
    t_cn    c;
    t_bool  error;
    
    c.r = 0.0;
    c.i = 0.0;
    error = FALSE;
    if (ft_strncmp(str[1], "Mandelbrot", ft_strlen_improve("Mandelbrot", '\0')) == 0)
    {
	mandelbrot(win);
	ft_hook(*win);
    }
    else if (ft_strncmp(str[1], "Julia", ft_strlen_improve("Julia", ' ')) == 0)
    {
	get_julia_value(&c, str, &error);
	if (error == TRUE)
	{
	 	free_img(win);
	    	error_message();
	    	exit(EXIT_FAILURE);
	}
		julia(win, c);
		ft_hook(*win);
    }
 }
