#include <stdlib.h>
#include "stack.h"
#include "libft.h"
#include "ft_printf.h"

//operations
void swap(t_stack *t);
void rotate(t_stack *t);
void r_rotate(t_stack *t);
void push_x(t_stack *dst, t_stack *src);
void print_stack(t_stack t);
void print_2stacks(t_stack a, t_stack b);