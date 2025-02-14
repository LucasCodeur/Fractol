# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lud-adam <lud-adam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 16:42:49 by lud-adam          #+#    #+#              #
#    Updated: 2025/02/04 15:31:18 by lud-adam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol
SRC_DIR := src
FTPRINTF_DIR := ft_printf
OBJ_DIR := obj
LIBFT_DIR := libft/
DEP_DIR := dep
INC_DIR := include

HEADERS := $(INC_DIR)/fractol.h
SRC := $(SRC_DIR)/fractol.c $(SRC_DIR)/main.c $(SRC_DIR)/mlx.c
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

MAKE := make -j --no-print-directory
CC := cc
CFLAGS := -Wall -Wextra -Werror -g -O3
INC := -I$(INC_DIR) -I/usr/include -Imlx_linux
LIBS := -Lmlx_linux -lmlx -lXext -lX11 -lm -lz
LIBFT := $(LIBFT_DIR)libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(INC) $^ $(LIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
	$(CC) -MM $(CFLAGS) $(INC) $< -MF $(DEP_DIR)/$*.d

$(LIBFT): FORCE
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean $(NAME)

FORCE: 

-include $(DEP)

.PHONY: all clean fclean re
