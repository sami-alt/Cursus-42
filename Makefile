# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 12:33:56 by sraiha            #+#    #+#              #
#    Updated: 2024/11/11 09:29:43 by sraiha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

NAME = libft.a


SRCS	= ft_atoi.c \
		  ft_bzero.c \
		  ft_calloc.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_memset.c \
		  ft_putchar_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strdup.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmapi.c \
		  ft_strncmp.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strtrim.c \
		  ft_substr.c \
		  ft_tolower.c \
		  ft_toupper.c 
		  
BONUS 	= 	ft_lstadd_front_bonus.c \
				ft_lstnew_bonus.c \
		   		ft_lstsize_bonus.c \
		  		ft_lstlast_bonus.c \
		  		ft_lstadd_back_bonus.c \
		  		ft_lstdelone_bonus.c \
		  		ft_lstclear_bonus.c \
		  		ft_lstiter_bonus.c \
		  		ft_lstmap_bonus.c 

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: ${NAME}

${NAME}: ${OBJS}
	ar -r $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	ar -r $(NAME) $^

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

clean:	
	rm -f ${OBJS} $(BONUS_OBJS)

fclean:
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus