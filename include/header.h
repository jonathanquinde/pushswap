#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

//operations
void swap(t_stack *t, char name);
void rotate(t_stack *t, char name);
void r_rotate(t_stack *t, char name);
void push_x(t_stack *dst, t_stack *src, char name);
void print_stack(t_stack t);
void print_2stacks(t_stack a, t_stack b);
void parse_input(t_stack *a, int argc, char **argv);