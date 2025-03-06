/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:21:44 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/16 20:21:44 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void stack_sort(t_stack *a, t_stack *b);
void move_min_to_top(t_stack *a, int min_index);
int find_min_index(t_stack *a);
void is_sorted(int	*arr, int size);

//4 5 -9 3 1

int main(int argc, char *argv[])
{
	t_stack a;
	t_stack b = stk_new(5);

	parse_input(&a, argc, argv);
	is_sorted(a.stack, a.capacity);
	stack_sort(&a, &b);
	free(a.stack);
	free(b.stack);
}

void is_sorted(int	*arr, int size)
{
	if (size == 1)	
	{
		free (arr);
		exit(EXIT_SUCCESS);
	}
	for (int i = 1; i < size; i++)
	{
		if (arr[i - 1] < arr[i])
			return ;
	}
	free (arr);
	exit(EXIT_SUCCESS);
}

/**
 * Find the index of the smallest element in stack A
 */
int find_min_index(t_stack *a)
{
	int min = stk_peek(a);
	int min_index = a->top;
	for (int i = a->top; i >= 0; i--)
	{
		if (a->stack[i] < min)
		{
			min = a->stack[i];
			min_index = i;
		}
	}
	return min_index;
}

/**
 * Moves the smallest element to the top using rotate/reverse rotate
 */
void move_min_to_top(t_stack *a, int min_index)
{
	if (min_index > a->top / 2)
	{
		// Closer to the top, use r_rotate
		while (min_index++ < a->top)
			r_rotate(a, 'a');
	}
	else
	{
		// Closer to the bottom, use rotate
		while (min_index-- > 0)
			rotate(a, 'a');
	}
}

/**
 * Sorts stack A using stack B as a buffer
 */
void stack_sort(t_stack *a, t_stack *b)
{
	while (!stk_is_empty(*a))
	{
		int min_index = find_min_index(a);
		move_min_to_top(a, min_index);
		push_x(b, a, 'b'); // pb
	}
	while (!stk_is_empty(*b))
	{
		push_x(a, b, 'a'); // pa
	}
}
