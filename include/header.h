/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:47:06 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 22:16:47 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "stack.h"
#include "math.h"
#include "libft.h"
#include "ft_printf.h"

//operations
void	swap(t_stack *t, char name);
void	sswap(t_stack *a, t_stack *b);
void	rotate(t_stack *t, char name);
void	r_rotate(t_stack *t, char name);
void	rrotate(t_stack *a, t_stack *b);
void	r_rrotate(t_stack *a, t_stack *b);
void	push_x(t_stack *dst, t_stack *src, char name);

void	sort_edges(t_stack *a, t_stack *b, int size);

void	sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void	sort_do(t_stack *a, char *ops, char name);

void	sort_4_a(t_stack *t, char *ops_a);
void	sort_4_b(t_stack *t, char *ops_b);
void	sort_3_a(t_stack a, char *operations);
void	sort_3_b(t_stack b, char *operations);
void	sort_just_3_a(t_stack *a, char *ops_a);
void	sort_just_3_b(t_stack *b, char *ops_b);

//utils
void	partition_stack_a(t_stack *a, t_stack *b, int range);
void	partition_stack_b(t_stack *b, t_stack *a, int range);
void	copy_stack(t_stack **dst, t_stack *src);
void	stk_free(t_stack *t);
int		pos_greater_by(t_stack *a, int pos, int range);
void	print_2stacks(t_stack *a, t_stack *b);

int		is_sorted(int	*arr, int range, int top);
int		is_sorted_rev(int	*arr, int range, int top);
int		find_median(t_stack *a, int range);

void	parse_input(t_stack **a, int argc, char **argv);