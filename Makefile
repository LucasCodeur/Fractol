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
FTPRINTF_DIR := ft_printf/
OBJ_DIR := obj/
DEP_DIR := dep/
INC_DIR := include/
HEADERS := $(INC_DIR)fractol.h
SRC := $(SRC_DIR)fractol.c $(SRC_DIR)main.c $(SRC_DIR)mlx.c
SRC_FTPRINTF := PRINTF
OBJ := $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEP := $(OBJ:$(OBJ_DIR)%.o=$(DEP_DIR)%.d)
MAKE := $(MAKE) -j --no-print-directory
CC := cc
CFLAGS := -Wall -Wextra -Werror -g
INC := -I$(INC_DIR)

$(NAME): $(OBJ) $(FTPRINTF)
	$(CC) $(CFLAGS) $(INC) $^ -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	$(CC) -MM $(CFLAGS) $(INC) $< > $(DEP_DIR)$*.d

$(FT_PRINT) : FORCE
	$(MAKE) -C $(FTPRINTF_DIR)

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

clean:
	$(MAKE) -C $(FTPRINTF_DIR) clean
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	$(MAKE) -C $(FTPRINTF_DIR) fclean
	rm -rf $(NAME)

re: fclean all

FORCE:

-include $(DEP)

.PHONY: all clean fclean re

