/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:03:00 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 11:38:35 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*sorted_array(int *arr, int size, int top);

void	partition_stack_a(t_stack *a, t_stack *b, int range)
{
	int	count_push;
	int	count_rotate;
	int	median;

	count_push = (int) floor(range / (double)2);
	count_rotate = 0;
	median = find_median(a, range);
	for (int i = 0; i < range; i++) 
	{
		if (count_push == 0)
			break ;
		if (stk_peek(a, 1) < median)
		{
			push_x(b, a, 'b');
			count_push--;
		}
		else if (stk_peek(a, a->top + 1) < median)
		{
			r_rotate(a, 'a');
			push_x(b, a, 'b');
			count_push--;
		}
		else
		{
			rotate(a, 'a');
			count_rotate++;
		}
	}
	while ((int) ceil(range / (double) 2) != a->top + 1 && count_rotate > 0)
	{
		r_rotate(a, 'a');
		count_rotate--;
	}
}

void	partition_stack_b(t_stack *b, t_stack *a, int range)
{
	int	count_push;
	int	count_rotate;
	int	median;

	count_push = (int) ceil(range / (double)2);
	count_rotate = 0;
	median = find_median(b, range);
	for (int i = 0; i < range; i++)
	{
		if (count_push == 0)
			break ;
		if (stk_peek(b, 1) >= median)
		{
			push_x(a, b, 'a');
			count_push--;
		}
		else if (stk_peek(b, b->top + 1) >= median)
		{
			r_rotate (b, 'b');
			push_x(a, b, 'a');
			count_push--;
		}
		else
		{
			rotate(b, 'b');
			count_rotate++;
		}
	}
	while ((int) floor(range / (double) 2) != b->top + 1 && count_rotate > 0)
	{
		r_rotate(b, 'b');
		count_rotate--;
	}
}

int	*sorted_array(int *arr, int size, int top)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * (size));
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[top - i];
		i++;
	}
	i = 1;
	for (int i = 1; i < size; i++)
	{
		int key = copy[i];
		int j = i - 1;
		while (j >= 0 && copy[j] > key) {
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = key;
	}
	return (copy);
}

//ft_printf("Copy: %d %d\n", copy[0], copy[range - 1]);
//ft_printf("Median: %d, range: %d\n", median, range);
int	find_median(t_stack *a, int range)
{
	int	*copy;
	int median;

	copy = sorted_array(a->stack, range, a->top);
	if (range % 2 == 1)
		median = copy[range / 2];
	else
		median = floor((copy[range / 2 + 1] + copy[range / 2]) / (double)2);
	free(copy);
	return (median);
}

int	is_sorted(int *arr, int range, int top)
{
	int	i;

	if (range < 2 || top < 1)
		return (1);
	i = top;
	while (i > top - range + 1)
	{
		if (arr[i] > arr[i - 1])  
			return (0);
		i--;
	}
	return (1);
}

int	is_sorted_rev(int *arr, int range, int top)
{
	int	i;

	if (range < 2 || top < 1)
		return (1);
	i = top;
	while (i > top - range + 1)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}
