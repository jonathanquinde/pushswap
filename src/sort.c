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

//sorteara 5= 3 2, 6= 3 3, 7= 4 3, 8= 4 4
void	sort_edges(t_stack *a, t_stack *b, int size)
{
	char	ops_a[13];
	char	ops_b[13];
	int		elms_parted;

	ft_bzero(ops_a, 13);
	ft_bzero(ops_b, 13);
	if (a->top + 1 == 3)
		sort_just_3_a(a, ops_a);
	else if (size == 4 || a->top + 1 == 4 || (int) ceil(size / (double)2) == 4)
		sort_4_a(a, ops_a);
	else if ((int) ceil(size / (double)2) == 3 || size == 3)
		sort_3_a(*a, ops_a);
	else if (size == 2 || (int) ceil(size / (double)2) == 2)
	{
		if (a->top > 0 && stk_peek(a, 1) > a->stack[a->top - 1]) 
			ops_a[0] = 's';
	}

	if (b->top + 1 == 3)
		sort_just_3_b(b, ops_b);
	else if (size == 4 || b->top + 1 == 4 || (int)floor(size / (double)2) == 4)
		sort_4_b(b, ops_b);
	else if ((int) floor(size / (double)2) == 3 || size == 3)
		sort_3_b(*b, ops_b);
	else if (size == 2 || (int)floor(size / (double)2) == 2)
	{
		if (b->top > 0 && stk_peek(b, 1) < b->stack[b->top - 1])
			ops_b[0] = 's';
	}
	//ft_printf("|%s|\n|%s|\n", ops_a, ops_b);
	//print_2stacks(a, b);
	sort_do(a, ops_a, 'a');
	sort_do(b, ops_b, 'b');
	//print_2stacks(a, b);
	elms_parted = (int) floor(size / (double)2);
	while (elms_parted > 0)
	{
		push_x(a, b, 'a');
		elms_parted--;
	}
	//sort_it(a, b, ops_a, ops_b);
}


