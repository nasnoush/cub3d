# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:48:13 by nadahman          #+#    #+#              #
#    Updated: 2025/05/12 08:38:16 by yaoberso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nas <nas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/28 13:48:13 by nadahman          #+#    #+#              #
#    Updated: 2025/05/07 19:24:55 by nas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

MLX_DIR = ./mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

INCLUDES = -I./includes -I$(MLX_DIR) -I./libft -I./get_next_line

SRCS_DIR = src
ASSETS_DIR = assets
PARSING_DIR = parsing
RENDER_DIR = render
UTILS_DIR = utils
GNL_DIR = get_next_line
INIT = init

SRCS = $(SRCS_DIR)/main.c \
	   $(wildcard $(ASSETS_DIR)/*.c) \
       $(wildcard $(SRCS_DIR)/$(PARSING_DIR)/*.c) \
	   $(wildcard $(GNL_DIR)/*.c) \
       $(wildcard $(SRCS_DIR)/$(UTILS_DIR)/*.c) \
       $(wildcard $(SRCS_DIR)/$(RENDER_DIR)/*.c) \
       $(wildcard $(SRCS_DIR)/$(INIT)/*.c)

OBJ = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_OBJ = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(MLX_DIR)/libmlx_Linux.a:
	make -C $(MLX_DIR)

$(LIBFT_OBJ):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_OBJ) $(MLX_DIR)/libmlx_Linux.a
	$(CC) $(OBJ) $(LIBFT_OBJ) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -O3 -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -f $(MLX_DIR)/libmlx_Linux.a

re: fclean all

.PHONY: all clean fclean re leaks