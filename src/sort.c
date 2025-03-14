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
		if (stk_peek(a, 1) < median) {
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
		if (stk_peek(b, 1) >= median) {
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

void sort_edges(t_stack *a, t_stack *b, int size)
{
	if (size == 2 || size == 4)
	{
		if (stk_peek(a, 1) > stk_peek(a, 2) && stk_peek(b, 1) < stk_peek(b, 2))
			sswap(a, b);
		else{
			if (a->top > 0 && stk_peek(a, 1) > a->stack[a->top - 1]) 
				swap(a, 'a');
			if (b->top > 0 && stk_peek(b, 1) < b->stack[b->top - 1]) 
				swap(b, 'b');
		}
	}
	if (size == 3 || size == 6)
	{
		sort_small_stack_a(a);
		sort_small_stack_b(b);
	}
}

void sort_small_stack_a(t_stack *a)
{
	if (stk_peek(a, 2) > stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3))
		return ;
	if (stk_peek(a, 1) > stk_peek(a, 2) && stk_peek(a, 1) > stk_peek(a, 3))
	{
		swap(a, 'a');
	}
	if (stk_peek(a, 2) < stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3))
	{
		swap(a, 'a');
		return ;
	}
	rotate(a, 'a');
	swap(a, 'a');
	r_rotate(a, 'a');
	if (stk_peek(a, 1) > stk_peek(a, 2))
		swap(a, 'a');
}

void sort_small_stack_b(t_stack *b)
{
	if (stk_peek(b, 2) < stk_peek(b, 1) && stk_peek(b, 2) > stk_peek(b, 3))
		return ;
	if (stk_peek(b, 1) < stk_peek(b, 2) && stk_peek(b, 1) < stk_peek(b, 3))
	{
		swap(b, 'b');
	}
	if (stk_peek(b, 2) > stk_peek(b, 1) && stk_peek(b, 2) > stk_peek(b, 3))
	{
		swap(b, 'b');
		return ;
	}
	rotate(b, 'b');
	swap(b, 'b');
	r_rotate(b, 'b');
	if (stk_peek(b, 1) < stk_peek(b, 2))
		swap(b, 'b');

}
