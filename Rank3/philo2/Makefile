/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-05 11:59:39 by sraiha            #+#    #+#             */
/*   Updated: 2025-04-05 11:59:39 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

NAME = philo

SRC = sources/phlosophers.c \
      sources/init.c \
      sources/actions.c \
      sources/monitoring.c \
      sources/utils.c \


OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all