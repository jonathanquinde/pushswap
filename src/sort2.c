/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:29:23 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/15 23:29:23 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_do(t_stack *a, char *ops, char name);
void	dual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b);
void	single_ops(t_stack *t,char *ops, char name);
void	mutual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b);

void sort_it(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{ 
	if (*ops_a == *ops_b && *ops_a == 's')
	{
		dual_ops(a, b, ops_a, ops_b);
		ops_a++;
		ops_b++;
	}
	else if (*ops_a == 's')
	{
		single_ops(a, ops_a, 'a');
		ops_a++;
	}
	else if (*ops_b == 's')
	{
		single_ops(b, ops_b, 'b');
		ops_b++;
	}
	if (*ops_a == 'r' && *ops_b == 'r')
	{
		mutual_ops(a, b, ops_a, ops_b);
		return ;
	}
	sort_do(a, ops_a, 'a');	
	sort_do(b, ops_b, 'b');
}

void	mutual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
{
	while (*ops_a && *ops_b)
	{
		dual_ops(a, b, ops_a, ops_b);
		ops_a++;
		ops_b++;
	}
	if (*ops_a == 0)
		sort_do(b , ops_b, 'b');
	else if (*ops_b == 0)
		sort_do(a , ops_a, 'a');
}
			
void single_ops(t_stack *t,char *ops, char name)
{
	if (*ops == 's')
		swap(t, name);
	else if (*ops == 'r')
		rotate(t, name);
	else if (*ops == 'd')
		r_rotate(t, name);
}

void    dual_ops(t_stack *a, t_stack *b, char *ops_a, char *ops_b)
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

void sort_do(t_stack *a, char *ops, char name)
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
