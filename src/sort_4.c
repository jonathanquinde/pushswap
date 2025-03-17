/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:17:35 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 20:44:43y jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_4__a(t_stack *a, char *ops_a);
void	sort_4__b(t_stack *b, char *ops_b);

void	sort_4_a(t_stack *t, char *ops_a)
{
	t_stack	*a;

	copy_stack(&a, t);
	if (pos_greater_by(a, 1, 4) == 4
		|| (pos_greater_by(a, 2, 4) == 1 && pos_greater_by(a, 1, 4) != 4))
	{
		swap(a, 'x');
		*ops_a++ = 's';
	}
	if (pos_greater_by(a, 1, 4) == 1)
	{
		*ops_a++ = 'r';
		rotate(a, 'x');
		sort_3_a(*a, ops_a);
		ops_a = ft_strchr(ops_a, '\0');
		r_rotate(a, 'x');
		*ops_a++ = 'd';
	}
	else if (pos_greater_by(a, 4, 4) == 4)
		sort_3_a(*a, ops_a);
	if (pos_greater_by(a, 1, 4 == 1) || pos_greater_by(a, 4, 4) == 4)
		stk_free(a);
	else
		sort_4__a(a, ops_a);
}

void	sort_4__a(t_stack *a, char *ops_a)
{
	if (pos_greater_by(a, 3, 4) == 4)
		*ops_a++ = 'r';
	*ops_a++ = 'r';
	*ops_a++ = 's';
	if (pos_greater_by(a, 3, 4) == 4)
		*ops_a++ = 'd';
	else
		*ops_a++ = 'r';
	*ops_a++ = 's';
	*ops_a++ = 'd';
	if (pos_greater_by(a, 3, 4) != 4)
	{
		if (pos_greater_by(a, 4, 4) == 1)
			*ops_a++ = 's';
		*ops_a++ = 'd';
	}
	*ops_a++ = 's';
	if (pos_greater_by(a, 1, 4) == 3)
	{
		*ops_a++ = 'r';
		*ops_a++ = 's';
		*ops_a++ = 'd';
	}
	stk_free(a);
}

void	sort_4_b(t_stack *t, char *ops_b)
{
	t_stack	*b;

	copy_stack(&b, t);
	if (pos_greater_by(b, 1, 4) == 1
		|| (pos_greater_by(b, 2, 4) == 4 && pos_greater_by(b, 1, 4) != 1))
	{
		swap(b, 'x');
		*ops_b++ = 's';
	}
	if (pos_greater_by(b, 1, 4) == 4)
	{
		*ops_b++ = 'r';
		rotate(b, 'x');
		sort_3_b(*b, ops_b);
		ops_b = ft_strchr(ops_b, '\0');
		r_rotate(b, 'x');
		*ops_b++ = 'd';
	}
	else if (pos_greater_by(b, 4, 4) == 1)
		sort_3_b(*b, ops_b);
	if (pos_greater_by(b, 1, 4 == 4) || pos_greater_by(b, 4, 4) == 4)
		stk_free(b);
	else
		sort_4__b(b, ops_b);
}

void	sort_4__b(t_stack *b, char *ops_b)
{
	if (pos_greater_by(b, 3, 4) == 1)
		*ops_b++ = 'r';
	*ops_b++ = 'r';
	*ops_b++ = 's';
	if (pos_greater_by(b, 3, 4) == 1)
		*ops_b++ = 'd';
	else
		*ops_b++ = 'r';
	*ops_b++ = 's';
	*ops_b++ = 'd';
	if (pos_greater_by(b, 3, 4) != 1)
	{
		if (pos_greater_by(b, 4, 4) == 4)
			*ops_b++ = 's';
		*ops_b++ = 'd';
	}
	*ops_b++ = 's';
	if (pos_greater_by(b, 1, 4) == 2)
	{
		*ops_b++ = 'r';
		*ops_b++ = 's';
		*ops_b++ = 'd';
	}
	stk_free(b);
}
