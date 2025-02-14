/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/08 17:17:40 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H 
# define FRACTOL_H
# define SCALE 270
# define MAX_WIDTH 1920
# define MAX_HEIGHT 1920
# define MAX_ITER 50
# define MIN_RE -2.0
# define MAX_RE 1.0
# define MIN_IM -1.5
# define MAX_IM 1.5
# define BLACK 0x000000


#include <../mlx_linux/mlx.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_img 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef	struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}				t_mlx;

typedef struct s_coord
{
	int		x;
	int		y;

}	t_coord;

typedef struct	s_cn
{
	double	r;
	double	i;
}				t_cn;

void	init_mlx(t_mlx *t_mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	free_mlx(t_mlx *t_mlx);
void	init_screen_mlx(t_mlx *t_mlx);
void	make_complex_plan(t_mlx *window);
void	mandelbrot(t_mlx *window);

#endif
