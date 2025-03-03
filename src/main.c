/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:35:04 by lud-adam          #+#    #+#             */
/*   Updated: 2025/03/03 16:54:32 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	data;
	int		max_width;
	int		max_height;

	if (argc < 2)
	{
		error_message();
		return (1);
	}
	init_screen_mlx(&data);
	mlx_get_screen_size(data.mlx, &max_width, &max_height);
	if (!data.mlx || !data.mlx_win || WIDTH > max_width || HEIGHT > max_height)
	{
		free_img(&data);
		return (1);
	}
	fractal_choice(argc, argv, &data);
	return (0);
}
