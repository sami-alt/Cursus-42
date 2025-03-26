# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 10:30:15 by sraiha            #+#    #+#              #
#    Updated: 2025/03/19 15:01:33 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror  -Wextra -g
INCLUDE = -I include
RM = rm -rf

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

MLXFLAGS = -Lminilibx-linux -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR = ./minilibx-linux
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
	@make -C ft_printf
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) $(MLX) $(MLXFLAGS) ft_printf/libftprintf.a -o $(NAME)

clean:
	@make clean -C $(LIBFT_DIR)
	@make  clean -C $(FT_PRINTF_DIR)
	@make clean -C $(MLX_DIR)
	rm -f $(OBJS) 


fclean:
	rm  -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@make  fclean -C $(FT_PRINTF_DIR)

re: fclean all

.PHONY: all bonus clean fclean re