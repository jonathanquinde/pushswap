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

void sort(t_stack *a, t_stack *b, int size);
void sort_recursive_a(t_stack *a, t_stack *b, int size);
void sort_recursive_b(t_stack *a, t_stack *b, int size);

int main(int argc, char *argv[])
{
	t_stack a;

	parse_input(&a, argc, argv);
	if (is_sorted(a.stack, a.capacity, a.top))
	{
		free (a.stack);
		return (0);
	}
	t_stack b = stk_new(a.capacity);
	if (b.stack == NULL)
		return (0);
	//print_2stacks(a, b);
    sort(&a, &b, a.top + 1);
	print_2stacks(a, b);
	free (a.stack);
	free (b.stack);
}

void sort_recursive_a(t_stack *a, t_stack *b, int size)
{
    ft_printf("Sort_a for %d size\n", size);
    print_2stacks(*a, *b);
    if (is_sorted(a->stack, size, a->top))
    {
        return ;
    }
    if (size <= 6)
    {
        if (size == 4 || size == 6)
        {
            ft_printf("Parting a on %d elements\n", size);
            partition_stack_a(a, b, size);
            print_2stacks(*a, *b);
        }
        ft_printf("Sorting\n");
        sort_edges(a, b, size);
        print_2stacks(*a, *b);

        push_x(a, b, 'a');
        push_x(a, b, 'a');
        push_x(a, b, 'a');
        return;
    }
    partition_stack_a(a, b, size);
    ft_printf("Parting a on %d elements\n", size);
    print_2stacks(*a, *b);

    sort_recursive_a(a, b, ceil(size / (double)2));
    sort_recursive_b(a, b, floor(size / (double)2));
}

void sort_recursive_b(t_stack *a, t_stack *b, int size)
{
    ft_printf("Sort_b for %d size\n", size);
    print_2stacks(*a, *b);
    if (is_sorted_rev(b->stack, size, b->top))
    {
        for (int i = 0; i < size; i++)
        {
            push_x(a, b, 'a');
        }
        return ;
    }
    if (size <= 6)
    {
        if (size == 4 || size == 6)
        {
            ft_printf("Parting b on %d elements\n", size);
            partition_stack_b(b, a, size);
            print_2stacks(*a, *b);
        }
        ft_printf("Sorting\n");
        sort_edges(a, b, size);
        print_2stacks(*a, *b);

        push_x(a, b, 'a');
        push_x(a, b, 'a');
        push_x(a, b, 'a');
        return;
    }
    partition_stack_b(b, a, size);
    ft_printf("Parting b on %d elements\n", size);
    print_2stacks(*a, *b);

    sort_recursive_a(a, b, ceil(size / (double)2));
    sort_recursive_b(a, b, floor(size / (double)2));
}

void sort(t_stack *a, t_stack *b, int size)
{
    partition_stack_a(a, b, size);

    sort_recursive_a(a, b, ceil(size / (double)2));
    sort_recursive_b(a, b, floor(size / (double)2));
}

//4 -> 2 2 -> 4

//8 -> 4 4 -> 2 2-4
//4 4 -> 4-2 2 -> 8

//16 -> 8 8