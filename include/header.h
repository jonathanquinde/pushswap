#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "math.h"
#include "libft.h"
#include "ft_printf.h"

//operations
void swap(t_stack *t, char name);
void sswap(t_stack *a, t_stack *b);
void rotate(t_stack *t, char name);
void r_rotate(t_stack *t, char name);
void rrotate(t_stack *a, t_stack *b);
void r_rrotate(t_stack *a, t_stack *b);
void push_x(t_stack *dst, t_stack *src, char name);
void print_stack(t_stack t);
void print_2stacks(t_stack a, t_stack b);

//sort2
void sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b);

//utils
void partition_stack_a(t_stack *a, t_stack *b, int range);
void partition_stack_b(t_stack *b, t_stack *a, int range);
int is_sorted(int	*arr, int range, int top);
int is_sorted_rev(int	*arr, int range, int top);
void parse_input(t_stack *a, int argc, char **argv);
int find_median(t_stack *a, int range);

//sort
void sort_edges(t_stack *a, t_stack *b, int size);