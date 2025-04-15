# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 11:59:39 by sraiha            #+#    #+#              #
#    Updated: 2025/04/15 15:20:34 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers



SRC = src/main.c \
	  src/cleanup.c \
	  src/init.c \
	  src/monitoring.c \
	  src/threads.c \
	  src/utils.c \
	  src/actions.c

OBJS =$(SRC:.=.o)

CC = cc
CFLAGS = -Wall -Werror  -Wextra -g
INCLUDE = -I include
RM = rm -rf


all:$(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(ONBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	fr -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re