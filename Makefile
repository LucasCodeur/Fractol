# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 16:42:49 by lud-adam          #+#    #+#              #
#    Updated: 2025/03/03 18:03:31 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
SRC_DIR := src
FTPRINTF_DIR := src/libft/ft_printf
OBJ_DIR := obj
LIBFT_DIR := src/libft/
MLX_DIR := minilibx-linux/minilibx-linux/
DEP_DIR := dep
INC_DIR := include

SRC := \
	src/error/error.c \
	src/fractal/fractal_choice.c \
	src/fractal/julia.c \
	src/fractal/mandelbrot.c \
	src/libft/compute_size_long.c \
	src/main.c \
	src/mlx/color.c \
	src/mlx/hooks.c \
	src/mlx/mlx.c \
	src/utils/functions_utils.c \

OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

MAKE := make -j
CC := cc
CFLAGS := -Wall -Wextra -Werror -Ofast
INC := -I$(INC_DIR) -I/usr/include -I$(MLX_DIR)
LIBS := -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
LIBFT := $(LIBFT_DIR)libft.a
MLX := $(MLX_DIR)libmlx.a $(MLX_DIR)libmlx_Linux.a 

all : $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(INC) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -MMD -MP -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)

force: 

-include $(DEP)

.PHONY: all clean fclean re
