# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:33:56 by sraiha            #+#    #+#              #
#    Updated: 2024/10/30 13:43:53 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = $(wildcard *.c)

OBJS = ${SRC:.c=.o}

all: ${NAME} clean

${NAME}: ${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:	
	rm -f ${OBJS}

fclean:
		rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re