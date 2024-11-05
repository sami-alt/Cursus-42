# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:33:56 by sraiha            #+#    #+#              #
#    Updated: 2024/11/05 15:53:08 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = $(wildcard *.c)

OBJS = $(SRC:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	rm -f ${OBJS}

fclean:
		rm -f ${NAME}

re: fclean all

so:
	gcc -shared -o libft.so $(OBJS)

.PHONY: all clean fclean re