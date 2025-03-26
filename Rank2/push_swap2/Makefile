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
SRC_DIR = src/
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC))

OBJS = $(SRC_FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

PRINTF_DIR = ./ft_printf
FT_PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = push_swap.c \
	  push.c \
	  swap.c \
	  rotate.c \
	  reverse_rotate.c \
	  utils.c \
	  sort.c \
	  quicksort.c


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME) : $(OBJS)
	@make -C ft_printf
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/libftprintf.a libft/libft.a -o $(NAME)

clean:
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re