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

MLXFLAGS = -Lmlx -lmlx -lXext -lX11

NAME = so_long 

SRC = src/so_long.c \

OBJS = $(SRC:.c=.o) 

all:$(NAME)

$(NAME):$(OBJS)
    $(CC) $(CFLAGS)  -o  $(NAME)  $(OBJS)  $(MLXFLAGS)

%.o: %.c
    $(CC) $(MXLFLAGS) -c $<  -o $@
