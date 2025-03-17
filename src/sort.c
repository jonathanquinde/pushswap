/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:39:07 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 16:24:19by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_just_3_a(t_stack *a, char *ops_a);
void	sort_just_3_b(t_stack *b, char *ops_b);

//ft_printf("|%s|\n|%s|\n", ops_a, ops_b);
//print_2stacks(*a, *b);

void	sort_edges(t_stack *a, t_stack *b, int size)
{
	char	ops_a[13];
	char	ops_b[13];

	ft_bzero(ops_a, 6);
	ft_bzero(ops_b, 6);
	if (a->top == 2)
		sort_just_3_a(a, ops_a);
	else if(size == 4)
		sort_4_a(*a, ops_a);
	else if ((int) ceil(size / (double)2) == 3 || size == 3)
		sort_3_a(*a, ops_a);
	else if (size == 2 || (int) ceil(size / (double)2) == 2)
	{
		if (a->top > 0 && stk_peek(a, 1) > a->stack[a->top - 1]) 
			ops_a[0] = 's';
	}

	if (b->top == 2)
		sort_just_3_b(b, ops_b);
	else if ((int) floor(size / (double)2) == 3 || size == 3)
		sort_3_b(*b, ops_b);
	else if (size == 2 || (int) floor(size / (double)2) == 2)
	{
		if (b->top > 0 && stk_peek(b, 1) < b->stack[b->top - 1])
			ops_b[0] = 's';
	}
	sort_it(a, b, ops_a, ops_b);
}


void	sort_just_3_a(t_stack *a, char *ops_a)
{
	if (stk_peek(a, 2) > stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3))
		return ;
	if (stk_peek(a, 1) > stk_peek(a, 2) && stk_peek(a, 1) > stk_peek(a, 3))
	{
		*ops_a++ = 'r';
		if (stk_peek(a, 3) < stk_peek(a, 1) && stk_peek(a, 3) < stk_peek(a, 2))
			*ops_a++ = 's';
	}
	else if (stk_peek(a, 2) > stk_peek(a, 1) && stk_peek(a, 2) > stk_peek(a, 3))
	{
		*ops_a++ = 'd';
		if (stk_peek(a, 1) < stk_peek(a, 2) && stk_peek(a, 1) < stk_peek(a, 3))
			*ops_a++ = 's';
	}
	else
	{
		*ops_a = 's';
	}
}

void	sort_just_3_b(t_stack *b, char *ops_b)
{
	if (stk_peek(b, 2) < stk_peek(b, 1) && stk_peek(b, 2) > stk_peek(b, 3))
		return ;
	if (stk_peek(b, 1) < stk_peek(b, 2) && stk_peek(b, 1) < stk_peek(b, 3))
	{
		*ops_b++ = 'r';
		if (stk_peek(b, 3) > stk_peek(b, 1) && stk_peek(b, 3) > stk_peek(b, 2))
			*ops_b++ = 's';
	}
	else if (stk_peek(b, 2) < stk_peek(b, 1) && stk_peek(b, 2) < stk_peek(b, 3))
	{
		*ops_b++ = 'd';
		if (stk_peek(b, 1) > stk_peek(b, 2) && stk_peek(b, 1) > stk_peek(b, 3))
			*ops_b++ = 's';
	}
	else
	{
		*ops_b = 's';
	}
}

void	sort_3_a(t_stack t, char *operations)
{
	t_stack	*a;
	int		*arr;

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

void	sort_3_b(t_stack t, char *operations)
{
	t_stack	*b;
	int		*arr;

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
