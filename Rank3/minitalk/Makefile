# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 09:21:28 by sraiha            #+#    #+#              #
#    Updated: 2025/03/17 15:27:00 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
PRINTF = libftprintf.a
LIBFT = libft.a
SRCC_FILES =	client.c
SRCS_FILES =	server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	 $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -s -C ft_printf
		@make -s -C  libft
		$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) libft/$(LIBFT) -o $(NAMEC)

$(NAMES) : $(OBJS)
		@make -s -C ft_printf
		$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)


clean :
		@make  clean -C ft_printf
		@make  clean -C libft
		${RM} ${OBJC}
		${RM} ${OBJS}
		${RM} ${OBJBC}
		${RM} ${OBJBS}

fclean : clean
		@make -s fclean -C ft_printf
		@make -s fclean -C libft
		${RM} ${NAMEC}
		${RM} ${NAMES}
		${RM} ${PRINTF}
		$(RM) ${LIBFT}

re : fclean all

.PHONY:		all bonus clean fclean re