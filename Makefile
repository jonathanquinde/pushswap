NAME = push_swap
SRC = src/*.c
PSRC = src/ft_printf/*.c
TEST = test/test_stacks.c

all:
	cc -I include -Wall -Werror -Wextra $(SRC) $(PSRC) src/libft.a -o $(NAME)
