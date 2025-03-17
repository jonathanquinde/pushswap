/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:35 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 17:25:46 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_pos_lesses_4(t_stack *a, int pos);
int	is_pos_greatest_4(t_stack *a, int pos);
int	is_first_3(t_stack *a);

void	sort_4_a(t_stack t, char *ops_a)
{
	t_stack	*a;
	int		*arr;

	a = &t;
	arr = malloc((a->top + 1) * sizeof(int));
	ft_memcpy(arr, t.stack, (t.top + 1) * sizeof(int));
	a->stack = arr;
	if (is_pos_greatest_4(a, 1))
	{
		swap(a, 'x');
		*ops_a++ = 's';
	}
	if (is_pos_lesses_4(a, 2))
	{
		if (!(is_pos_greatest_4(a, 4)))
		{
			*ops_a++ = 's';
			swap(a, 'x');
		}
	}
	if (is_pos_lesses_4(a, 1))
	{
		rotate(a, 'x');
		sort_3_a(*a, ops_a);
		ops_a = ft_strchr(ops_a, '\0');
		*ops_a++ = 'r';
		*ops_a++ = 'd';
		return ;
	}
	if (is_pos_greatest_4(a, 4))
	{
		sort_3_a(*a, ops_a);
		return ;
	}
	if (is_pos_greatest_4(a, 3))
		*ops_a++ = 'r';
	*ops_a++ = 'r';
	*ops_a++ = 's';
	if (is_pos_greatest_4(a, 3))
		*ops_a++ = 'd';
	else
		*ops_a++ = 'r';
	*ops_a++ = 's';
	*ops_a++ = 'd';
	if (is_pos_lesses_4(a, 4))
		*ops_a++ = 's';
	*ops_a++ = 'd';
	*ops_a++ = 's';
	if (is_first_3(a))
	{
		*ops_a++ = 'r';
		*ops_a++ = 's';
		*ops_a++ = 'd';
	}
}

int	is_first_3(t_stack *a)
{
	int	count;

	count = 0;
	if (stk_peek(a, 1) > stk_peek(a, 2))
		count++;
	if (stk_peek(a, 1) > stk_peek(a, 3))
		count++;
	if (stk_peek(a, 1) > stk_peek(a, 4))
		count++;
	if (count == 2)
		return (1);
	return (0);
}

int	is_pos_greatest_4(t_stack *a, int pos)
{
	if (pos == 1)
	{
		if (stk_peek(a, 1) > stk_peek(a, 2) && stk_peek(a, 1) > stk_peek(a, 3)
			&& stk_peek(a, 1) > stk_peek(a, 4))
			return (1);
	}
	else if (pos == 3)
	{
		if (stk_peek(a, 3) > stk_peek(a, 1) && stk_peek(a, 3) > stk_peek(a, 2)
			&& stk_peek(a, 3) > stk_peek(a, 4))
			return (1);
	}
	else if (pos == 4)
	{
		if (stk_peek(a, 4) > stk_peek(a, 3) && stk_peek(a, 4) > stk_peek(a, 2)
			&& stk_peek(a, 4) > stk_peek(a, 1))
			return (1);
	}
	return (0);
}

int	is_pos_lesses_4(t_stack *a, int pos)
{
	if (pos == 2)
	{
		if (stk_peek(a, 2) < stk_peek(a, 1) && stk_peek(a, 2) < stk_peek(a, 3)
			&& stk_peek(a, 2) < stk_peek(a, 4))
			return (1);
	}
	else if (pos == 3)
	{
		if (stk_peek(a, 3) < stk_peek(a, 1) && stk_peek(a, 3) < stk_peek(a, 2)
			&& stk_peek(a, 3) < stk_peek(a, 4))
			return (1);
	}
	else if (pos == 4)
	{
		if (stk_peek(a, 4) < stk_peek(a, 1) && stk_peek(a, 4) < stk_peek(a, 2)
			&& stk_peek(a, 4) < stk_peek(a, 3))
			return (1);
	}
	else if (pos == 1)
	{
		if (stk_peek(a, 1) < stk_peek(a, 2) && stk_peek(a, 1) < stk_peek(a, 3)
			&& stk_peek(a, 1) < stk_peek(a, 4))
			return (1);
	}
	return (0);
}
