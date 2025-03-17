/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:39:54 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 21:49:12 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	pos_greater_by(t_stack *a, int pos, int range)
{
	int	count;
	int	i;

	count = 0;
	i = 1;
	while (i <= range)
	{
		if (stk_peek(a, pos) >= stk_peek(a, i))
			count++;
		i++;
	}
	return (count);
}

void	stk_free(t_stack *t)
{
	free(t->stack);
	free (t);
}

void	copy_stack(t_stack **dst, t_stack *src)
{
	*dst = stk_new(src->capacity);
	(*dst)->top = src->top;
	ft_memcpy((*dst)->stack, src->stack, (src->top + 1) * sizeof(int));
}

/*
*/
void	print_2stacks(t_stack *a, t_stack *b)
{
	int	i;

	ft_printf(" a \t b \n");
	if (a->top >= b->top)
		i = a->top;
	else
		i = b->top;
	while (i >= 0)
	{
		if (i > a->top)
		{
			ft_printf("   \t %d \n", b->stack[i]);
		}
		else if (i > b->top)
		{
			ft_printf(" %d  \t   \n", a->stack[i]);
		}
		else
		{
			ft_printf(" %d \t %d \n", a->stack[i], b->stack[i]);
		}
		i--;
	}
	ft_printf("----------\n");
}
