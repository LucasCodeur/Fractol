/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:04 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 18:34:06 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	window;
	int		i;

	i = 1;
	if (argc < 2)
	{
		error_message();
		return (1);
	}
	init_screen_mlx(&window);
	if (!window.mlx || !window.mlx_win)
	{
		free_img(&window);
		return (1);
	}
	fractal_choice(argc, argv, &window);
	return (0);
}
