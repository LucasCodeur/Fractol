/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/17 19:10:12 by lud-adam         ###   ########.fr       */
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
# define MAX_SCALE 1000.0f
# define MIN_SCALE 0.0001f
# define ZOOM_IN(scale) ((scale) *= 1.1)
# define ZOOM_OUT(scale) ((scale) /= 1.1)

#include "../libft/libft.h"
#include <../mlx_linux/mlx.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>


//TODO to take of 
#include <stdio.h>

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
	double	scale;
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

//MLX
void	init_mlx(t_mlx *t_mlx);
void	init_screen_mlx(t_mlx *t_mlx);
void	free_img(t_mlx *t_mlx);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//HOOKS
int		key_press(int keycode, void *param);
int		close_win(void *param);
int		mouse_hook(int button, t_mlx *win);

// COLORD

int		get_color(int i);

// MATHS
void	map_to_complex(int x, int y, double *re, double *im, t_mlx *win);
void	mandelbrot(t_mlx *window);

#endif
