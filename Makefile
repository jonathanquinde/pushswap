NAME = push_swap
SRC = src/operations.c src/parsing.c src/push_swap.c src/stack.c src/utils.c src/sort.c
PSRC = src/ft_printf/*.c
TEST = test/test_stacks.c
FLAGS = -Wall -Werror -Wextra

all:
	cc -I include  $(SRC) $(PSRC) src/libft.a -lm -o $(NAME)
