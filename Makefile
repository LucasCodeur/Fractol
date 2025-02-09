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
OBJ_DIR := obj
DEP_DIR := dep
INC_DIR := include

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP := $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

CC := cc
CFLAGS := -Wall -Wextra -Werror
INC := -I$(INC_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -Lmlx_linux -lmlx -lXext -lX11 -lm -lz -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
	$(CC) -MM $(CFLAGS) $(INC) $< > $(DEP_DIR)/$*.d

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re

