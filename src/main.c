/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:04 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 18:00:14 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_render(char *str, t_mlx *win)
{
    t_cn    c;
    t_bool  error;
    
    c.r = 0.0;
    c.i = 0.0;
    error = FALSE;
    if (ft_strncmp(str, "Mandelbrot", ft_strlen_improve(str, "\0")) == 1)
	mandelbrot(win);
    else if (ft_strncmp(str, "Julia", ft_strlen_improve(str, " ")) == 1)
    {
	ft_atod(&c, &str[ft_strlen_improve(str, " ") + 1], &error);
	if (error = TRUE)
	{
	    free_img(win);
	    error_message;
	    exit(EXIT_FAILURE);
	}
	julia(win, c);
    }
 }

int main(int argc, char **argv)
{
    t_mlx   window;
    int	    i;
    
    i = 1;
    init_screen_mlx(&window);
    if (!window.mlx || !window.mlx_win)
    {
	    free_img(&window);
	    return (1);
    }
    ft_render(argv[i], &window);
    return (0);
}
