/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 10:30:15 by sraiha            #+#    #+#             */
/*   Updated: 2025-02-13 10:30:15 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

CC = cc

CFLAGS = -g -Wall -Werror -Wextra 

MLXFLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

MLX_DIR = ./mlx

MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

LIBFT_DIR = ./libft

NAME = so_long 

SRC = src/so_long.c

OBJS = $(SRC:.c=.o) 

all:$(MLX_LIB) $(NAME) 

$(NAME):$(OBJS)
    $(CC) $(CFLAGS)  -o  $(NAME)  $(OBJS)  $(MLXFLAGS)

%.o: %.c
    $(CC) $(MXLFLAGS) -c $<  -o $@

OBJS = $(SRCS:.c=.o)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	$(RM) $(RMFLAG) $(OBJS)

fclean: clean
	$(RM) $(RMFLAG) $(NAME)
	if [ -d "./mlx" ]; then make -C $(MLX_DIR) clean; fi

re: fclean all

.PHONY: all clean run fclean re 