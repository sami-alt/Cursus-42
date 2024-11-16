# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 10:34:01 by sraiha            #+#    #+#              #
#    Updated: 2024/09/25 22:13:57 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = bsq

SRC = main.c bsq.c utils.c read.c solver.c

PRE = src/

INCS = ./includes/

SRCS = ${addprefix ${PRE}, ${SRC}}

OBJS = ${SRCS:.c=.o}

all: ${NAME}

.c.o: 
	${CC}  ${FLAGS} -c -I ${INCS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
				${CC} ${FLAGS} -o ${NAME} ${OBJS}

clean:	
	rm -rf  ${OBJS}

fclean: clean 
			rm -rf ${NAME}

re: fclean all