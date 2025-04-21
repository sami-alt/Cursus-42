# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 11:59:39 by sraiha            #+#    #+#              #
#    Updated: 2025/04/16 13:20:40 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src/main.c \
	  src/cleanup.c \
	  src/init.c \
	  src/monitoring.c \
	  src/threads.c \
	  src/utils.c \
	  src/actions.c

OBJS =$(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror  -Wextra -g
INCLUDE = -I include
RM = rm -rf


all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re