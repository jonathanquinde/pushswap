/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:29:23 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/18 14:36:53 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void	single_ops(t_stack *t,char *ops, char name);
void	mutual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void	apply_sort_a(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void	apply_sort_b(t_stack *a, t_stack *b, char *ops_a, char *ops_b);

void	sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{
	if (ft_strlen(ops_a) >= ft_strlen(ops_b))
		apply_sort_a(a, b, ops_a, ops_b);
	else
		apply_sort_b(a, b, ops_a, ops_b);
}

void	apply_sort_a(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{
	while (*ops_a)
	{
		if (*ops_a == *ops_b)
		{
			dual_ops(a, b, ops_a, ops_b);
			ops_b++;
		}
		else
			single_ops(a, ops_a, 'a');
		ops_a++;
	}
	sort_do(b, ops_b, 'b');
}

void	apply_sort_b(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{
	while (*ops_b)
	{
		if (*ops_a == *ops_b)
		{
			dual_ops(a, b, ops_a, ops_b);
			ops_a++;
		}
		else
			single_ops(b, ops_b, 'b');
		ops_b++;
	}
	sort_do(a, ops_a, 'a');
}

void	single_ops(t_stack *t, char *ops, char name)
{
	if (*ops == 's')
		swap(t, name);
	else if (*ops == 'r')
		rotate(t, name);
	else if (*ops == 'd')
		r_rotate(t, name);
}

void	dual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{
	if (*ops_a == 's' && *ops_b == 's')
	{
		sswap(a, b);
	}
	else if (*ops_a == 'r' && *ops_b == 'r')
	{
		rrotate(a, b);
	}
	else if (*ops_a == 'd' && *ops_b == 'd')
	{
		r_rrotate(a, b);
	}

}

void	sort_do(t_stack *a, char *ops, char name)
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
