# Variables
NAME = push_swap

SRC = src/operations.c src/parsing.c src/push_swap.c src/stack.c src/utils.c src/sort.c src/sort2.c src/sort_4.c
PSRC = src/ft_printf/*.c

FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE = -I include

# Default rule: All
all: $(NAME)

# Rule for compiling the push_swap executable
$(NAME): $(SRC) $(PSRC) $(LIBFT)
	cc $(INCLUDE) $(FLAGS) $(SRC) $(PSRC) $(LIBFT) -lm -o $(NAME)

# Rule for compiling libft.a (if it changes)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean up object files and binaries
clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(NAME)

# Remove everything, including libft.a and the executable
fclean: clean
	make -C $(LIBFT_DIR) fclean

# Rebuild everything from scratch
re: fclean all
