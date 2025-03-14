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

void sort_small_stack_a(t_stack a, char *operations);
void sort_small_stack_b(t_stack b, char *operations);
void sort_3_6(t_stack *a, t_stack *b);

void partition_stack_a(t_stack *a, t_stack *b, int range)
{
	int count_push = (int) floor(range / (double)2);
	int count = 0;
	int median = find_median(a, range);
    ft_printf("median: %d", median);
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
	int count_push = (int) ceil(range / (double)2);
	int count_rotate = 0;
	int median = find_median(b, range);
    ft_printf("median: %d", median);
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
	char	ops_a[6] = {0};
	char	ops_b[6] = {0};
	int		i;

    if (size == 2 || (int) ceil(size / (double)2) == 2)
    {
        if (a->top > 0 && stk_peek(a, 1) > a->stack[a->top - 1]) 
            ops_a[0] = 's';
    }
    else if (size == 3 ||(int) ceil(size / (double)2) == 3)
    	sort_small_stack_a(*a, ops_a);
    if (size == 2 || (int) floor(size / (double)2) == 2)
    {
        if (b->top > 0 && stk_peek(b, 1) < b->stack[b->top - 1]) 
            ops_b[0] = 's';
    }
    else if (size == 3 || (int) floor(size / (double)2) == 3)
    	sort_small_stack_b(*b, ops_b);
	i = 0;
	while (ops_a[i])
	{
		if (ops_a[i] == 's')
			swap(a, 'a');
		else if (ops_a[i] == 'r')
			rotate(a, 'a');
		else if (ops_a[i] == 'd')
			r_rotate(a, 'a');
		i++;
	}
	i = 0;
	while (ops_b[i])
	{
		if (ops_b[i] == 's')
			swap(b, 'b');
		else if (ops_b[i] == 'r')
			rotate(b, 'b');
		else if (ops_b[i] == 'd')
			r_rotate(b, 'b');
		i++;
	}
}

void sort_small_stack_a(t_stack t, char *operations)
{
    t_stack *a;
    int     *arr;

    a = &t;
    arr = malloc((a->top + 1) * sizeof(int));
    ft_memcpy(arr, t.stack, (t.top + 1) * sizeof(int));
    a->stack = arr;
	if (stk_peek(a, 2) > stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3))
	{
		*operations = '\0';
        free (arr);
		return ;
	}
	if (stk_peek(a, 1) > stk_peek(a, 2) && stk_peek(a, 1) > stk_peek(a, 3))
	{
		*operations++ = 's';
        swap(a, 'x');
	}
	if (stk_peek(a, 2) < stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3))
	{
		*operations++ = 's';
		*operations = '\0';
        free (arr);
		return ;
	}
	*operations++ = 'r';
    rotate(a, 'x');
	*operations++ = 's';
    swap(a, 'x');
	*operations++ = 'd';
    r_rotate(a, 'x');
	if (stk_peek(a, 1) > stk_peek(a, 2))
    {
		*operations++ = 's';
    }
	*operations = '\0';
    free (arr);
}

void sort_small_stack_b(t_stack t, char *operations)
{
    t_stack *b;
    int     *arr;

    b = &t;
    arr = malloc((b->top + 1) * sizeof(int));
    ft_memcpy(arr, t.stack, (t.top + 1) * sizeof(int));
    b->stack = arr;
	if (stk_peek(b, 2) < stk_peek(b, 1) && stk_peek(b, 2) > stk_peek(b, 3))
	{
		*operations = '\0';
        free (arr);
		return ;
	}
	if (stk_peek(b, 1) < stk_peek(b, 2) && stk_peek(b, 1) < stk_peek(b, 3))
	{
		*operations++ = 's';
        swap(b, 'x');
	}
	if (stk_peek(b, 2) > stk_peek(b, 1) && stk_peek(b, 2) > stk_peek(b, 3))
	{
		*operations++ = 's';
		*operations = '\0';
        free (arr);
		return ;
	}
	*operations++ = 'r';
    rotate(b, 'x');
	*operations++ = 's';
    swap(b, 'x');
	*operations++ = 'd';
    r_rotate(b, 'x');
	if (stk_peek(b, 1) < stk_peek(b, 2))
		*operations++ = 's';
	*operations = '\0';
    free (arr);
}
