# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 10:30:15 by sraiha            #+#    #+#              #
#    Updated: 2025/02/28 13:15:22 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror  -Wextra
INCLUDE = -I include
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx_Linux.a

SRC = so_long.c \
	  draw_map.c \
	  free_game.c \
	  keys.c \
	  run_game.c \
	  error.c \
	  validate_map.c

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS) 


fclean:
	rm  -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re