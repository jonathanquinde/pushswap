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
void sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void sort_it2(t_stack *a, char *ops, char name);

void partition_stack_a(t_stack *a, t_stack *b, int range)
{
	int count_push = (int) floor(range / (double)2);
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
	int count_push = (int) ceil(range / (double)2);
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
	char	ops_a[6] = {0};
	char	ops_b[6] = {0};

    if (size == 3 || (int) ceil(size / (double)2) == 3)
    	sort_small_stack_a(*a, ops_a);
    else if (size == 2 || (int) ceil(size / (double)2) == 2)
    {
        if (a->top > 0 && stk_peek(a, 1) > a->stack[a->top - 1]) 
            ops_a[0] = 's';
    }
    if (size == 3 || (int) floor(size / (double)2) == 3)
    	sort_small_stack_b(*b, ops_b);
    else if (size == 2 || (int) floor(size / (double)2) == 2)
    {
        if (b->top > 0 && stk_peek(b, 1) < b->stack[b->top - 1]) 
            ops_b[0] = 's';
    }
    if (ops_a[0] == 0)
        sort_it2(b, ops_b, 'b');
    else if (ops_b[0] == 0)
        sort_it2(a, ops_a, 'a');
    else
        sort_it(a, b, ops_a, ops_b);
}

void sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{ 
    if (ops_a[1] == 0)
    {
        if (ops_b[1] == 'r' || ops_b[0] == 'r')
        {
            if (ops_b[0] == 's')
                swap(b, 'b');
			rotate(b, 'b');
            sswap(a, b);
            r_rotate(b, 'b');
            if (ops_b[4] == 's' || ops_b[3] == 's')
                swap(b, 'b');
            return ;
        }
    }
    if (ops_b[1] == 0)
    {
        if (ops_a[1] == 'r' || ops_a[0] == 'r')
        {
            if (ops_a[0] == 's')
                swap(a, 'a');
			rotate(a, 'a');
            sswap(a, b);
            r_rotate(a, 'a');
            if (ops_a[4] == 's' || ops_a[3] == 's')
                swap(a, 'a');
            return ;
        }
    }
    while (*ops_a || *ops_b)
    {
        // Swap both if both have 's', otherwise swap individually
        if (*ops_a == 's' && *ops_b == 's')
        {
            sswap(a, b);
            ops_a++;
            ops_b++;
        }
        else 
        {
            if (*ops_a == 's') swap(a, 'a'), ops_a++;
            if (*ops_b == 's') swap(b, 'b'), ops_b++;
        }
        // Process the 'r s d' pattern
        if ((*ops_a == 'r' && *ops_b == 'r'))
        {
            rrotate(a, b);   // Rotate both
            sswap(a, b);      // Swap both
            r_rrotate(a, b);  // Reverse rotate both

            ops_a += 3;  // Skip 'r s d'
            ops_b += 3;
        }
    }
}

void sort_it2(t_stack *a, char *ops, char name)
{
    while (*ops)
    {
        if (*ops == 's')
			swap(a, name);
		else if (*ops == 'r')
			rotate(a, name);
		else if (*ops == 'd')
			r_rotate(a, name);
        ops++;
    }
}

//s + rsd + s
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
