NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c \
	src/operations/push.c \
	src/operations/reverse_rotate.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/parsing/parse.c \
	src/parsing/stack_init.c \
	src/parsing/validation.c \
	src/sorting/indexing.c \
	src/sorting/radix.c \
	src/sorting/small_sort.c \
	src/sorting/sort.c \
	src/utils/free.c \
	src/utils/stack_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all