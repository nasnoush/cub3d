# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nadahman <nadahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:48:13 by nadahman          #+#    #+#              #
#    Updated: 2025/04/28 13:50:38 by nadahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC      = gcc
MLX_DIR = ./mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
INCLUDES = -I./GNL -I$(MLX_DIR)

SRCS    = main.c \

OBJ     = $(SRCS:.c=.o)

all: $(NAME)

$(MLX_DIR)/libmlx_Linux.a:
	make -C $(MLX_DIR)

$(NAME): $(OBJ) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make clean -C $(MLX_DIR)

re: fclean all

leaks: $(NAME)
	@echo "Test de fuites.."
	@valgrind --leak-check=full ./$<

.PHONY: all clean fclean re leaks
