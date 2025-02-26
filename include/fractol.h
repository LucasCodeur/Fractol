/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:02:15 by lud-adam          #+#    #+#             */
/*   Updated: 2025/02/24 18:12:11 by lud-adam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H 
# define FRACTOL_H
# define SCALE 270
# define MAX_WIDTH 500
# define MAX_HEIGHT 500
# define MAX_ITER 50
# define MIN_RE_J -2.0
# define MAX_RE_J 2.0
# define MIN_IM_J -2.0
# define MAX_IM_J 2.0

# define MIN_RE_M -2.0
# define MAX_RE_M 1.0
# define MIN_IM_M -1.5
# define MAX_IM_M 1.5

# define BLACK 0x000000
# define MAX_SCALE 1000.0
# define MIN_SCALE 0.0001
# define MAX_DOUBLE 1.797693e+308
# define MIN_DOUBLE 2.225074e-308

# include "../src/libft/libft.h"
# include <../mlx_linux/mlx.h>
# include <math.h>
# include <stdlib.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}					t_img;

typedef struct s_cn
{
	double	r;
	double	i;
}				t_cn;

typedef struct s_coord
{
	int		x;
	int		y;

}	t_coord;

typedef struct s_mlx
{
	t_cn	c;
	t_cn	z;
	t_coord	coord;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
	double	scale;
}				t_mlx;

typedef struct s_decimal_nb
{
	int			i;
	double		int_part;
	double		dec_part;
	double		sign;
	long double	result;
	int			of_decs;
	t_bool		dot_encounter;
}				t_decimal_nb;
//MLX
void		init_mlx(t_mlx *t_mlx);
void		init_screen_mlx(t_mlx *t_mlx);
void		free_img(t_mlx *t_mlx);
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);

//HOOKS
int			key_press(int keycode, void *param);
int			close_win(void *param);
void		hook_julia(t_mlx window);
void		hook_mandelbrot(t_mlx window);

// COLOR
int			get_color(int i);

// MATHS
void		mandelbrot(t_mlx *window);
void		julia(t_mlx *win);

//Fractal choice
void		fractal_choice(int argc, char **str, t_mlx *win);

// UTILS
long double	ft_atod(char *str);

// Errors
void		error_message(void);

#endif
