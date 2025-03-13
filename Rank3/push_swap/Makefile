# ************************************************************************** */
#                                                                            */
#                                                        :::      ::::::::   */
#   Makefile                                           :+:      :+:    :+:   */
#                                                    +:+ +:+         +:+     */
#   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
#                                                +#+#+#+#+#+   +#+           */
#   Created: 2025-03-13 16:29:48 by sraiha            #+#    #+#             */
#   Updated: 2025-03-13 16:29:48 by sraiha           ###   ########.fi       */
#                                                                            */
# ************************************************************************** */

NAME = push_swap
SRC_DIR = src
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

PRINTF_DIR = ./ft_printf
FT_PRINTF = $(PRINTF_DIR)/libprintf.a

SRC = push_swap.c \
	  push.c \
	  swap.c \
	  rotate.c \
	  reverse_rotate.C \
	  utils.c \
	  sort.c \
	  quicksort.c


all: $(NAME)

%.c: %.o
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	@make -C ft_printf
	$(CC) $(CFLAGS) $(INCLUDE) $(FT_PRINTF) -o $(NAME)

clean:
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS)

fclean:
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

.PHONY: all clean fclean re