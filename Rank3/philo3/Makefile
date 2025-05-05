NAME = philo

SRC = sources/main.c \
      sources/init.c \
      sources/threads.c \
      sources/actions.c \
      sources/monitoring.c \
      sources/utils.c \
      sources/cleanup.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) -I includes $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all