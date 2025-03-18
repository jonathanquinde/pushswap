/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:21:44 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 22:33:57by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mini_sort(t_stack *a, int size);
void	medium_sort(t_stack *a, t_stack *b, int size);
void	sort(t_stack *a, t_stack *b, int size);
void	sort_recursive_a(t_stack *a, t_stack *b, int size);
void	sort_recursive_b(t_stack *a, t_stack *b, int size);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	parse_input(&a, argc, argv);
	if (is_sorted(a->stack, a->capacity, a->top))
	{
		stk_free(a);
		return (0);
	}
	b = stk_new(a->capacity);
	if (a->top + 1 < 5)
		mini_sort(a, a->top + 1);
	else if (a->top + 1 < 9)
		medium_sort(a, b, a->top + 1);
	else
		sort(a, b, a->top + 1);
	print_2stacks(a, b);
	stk_free(a);
	stk_free(b);
}

void	sort_recursive_a(t_stack *a, t_stack *b, int size)
{
	if (is_sorted(a->stack, size, a->top))
		return ;
	if (size <= 8)
	{
		if (size > 4)
			partition_stack_a(a, b, size);
		sort_edges(a, b, size);

		return ;
	}
	partition_stack_a(a, b, size);

	sort_recursive_a(a, b, ceil(size / (double)2));
	sort_recursive_b(a, b, floor(size / (double)2));
}

void	sort_recursive_b(t_stack *a, t_stack *b, int size)
{
	int	i;

	if (is_sorted_rev(b->stack, size, b->top))
	{
		i = 0;
		while (i < size)
		{
			push_x(a, b, 'a');
			i++;
		}
		return ;
	}
	if (size <= 8)
	{
		if (size > 4)
			partition_stack_b(b, a, size);
		sort_edges(a, b, size);
		return ;
	}
	partition_stack_b(b, a, size);

	sort_recursive_a(a, b, ceil(size / (double)2));
	sort_recursive_b(a, b, floor(size / (double)2));
}

void	sort(t_stack *a, t_stack *b, int size)
{
	partition_stack_a(a, b, size);

	sort_recursive_a(a, b, ceil(size / (double)2));
	sort_recursive_b(a, b, floor(size / (double)2));
}

void	medium_sort(t_stack *a, t_stack *b, int size)
{
	partition_stack_a(a, b, size);
	sort_edges(a, b, size);
}

void	mini_sort(t_stack *a, int size)
{
	char	ops[13];

	ft_bzero(ops, 13);
	if (size == 2)
	{
		if (stk_peek(a, 1) > stk_peek(a, 2))
			ops[0] = 's';
	}
	else if (size == 3)
		sort_just_3_a(a, ops);
	else if (size == 4)
		sort_4_a(a, ops);
	sort_do(a, ops, 'a');
}
