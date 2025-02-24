/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:04 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 14:55:53 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

// int main(void)
// {
//     t_mlx window;
//
//     init_screen_mlx(&window);
//     if (!window.mlx || !window.mlx_win)
//     {
// 	    free_img(&window);
// 	    return 1;
//     }
//     mandelbrot(&window);
//     // julia(&window);
//     mlx_hook(window.mlx_win, 2, 1L<<0, key_press, &window);
//     mlx_hook(window.mlx_win, 17, 0, close_win, &window);
//     mlx_hook(window.mlx_win, 4, 1L<<2, mouse_hook, &window);
//     mlx_loop(window.mlx);
//     free_img(&window);
//     return (0);
// }

int main(int argc, char **argv)
{
    double  test;

    test = ft_convert_one_double(argv[1]);
    printf("%f", test);
    return (0);
}
