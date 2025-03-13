/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:39:07 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/11 22:39:07 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void sort_small_stack_a(t_stack *a);
void sort_small_stack_b(t_stack *a);

void partition_stack_a(t_stack *a, t_stack *b, int range)
{
    int count_push = range / 2;
    int count = 0;
	int median = find_median(a, range);
	for (int i = 0; i < range; i++) {
        if (count_push == 0)
            break ;
		if (stk_peek(a) < median) {
			push_x(b, a, 'b');
            count_push--;
		} else {
			rotate(a, 'a');
            count++;
		}
	}
    while (range / 2 != a->top + 1 && count > 0)
    {
        r_rotate(a, 'a');
        count--;
    }
}

void partition_stack_b(t_stack *b, t_stack *a, int range)
{
    int count_push = range / 2;
    int count_rotate = 0;
	int median = find_median(b, range);
	for (int i = 0; i < range; i++) {
        if (count_push == 0)
            break ;
		if (stk_peek(b) >= median) {
			push_x(a, b, 'a');
            count_push--;
		} else {
            rotate(b, 'b');
            count_rotate++;
		}
	}
    while (range / 2 != b->top + 1 && count_rotate > 0)
    {
        r_rotate(b, 'b');
        count_rotate--;
    }
}

void sort_edges(t_stack *a, t_stack *b)
{
    if (stk_peek(a) > a->stack[a->top - 1] && stk_peek(b) < b->stack[b->top - 1])
        sswap(a, b);
    else{
        sort_small_stack_a(a);
        sort_small_stack_b(b);
    }
}

void sort_small_stack_a(t_stack *a)
{
	if (a->top > 0 && stk_peek(a) > a->stack[a->top - 1]) 
		swap(a, 'a');
}

void sort_small_stack_b(t_stack *a)
{
	if (a->top > 0 && stk_peek(a) < a->stack[a->top - 1]) 
		swap(a, 'b');
}
