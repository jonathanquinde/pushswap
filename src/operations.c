/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:08:16 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 20:59:57 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap(t_stack *t, char name)
{
	int	temp;

	if (t->top < 1)
		return ;
	temp = t->stack[t->top];
	t->stack[t->top] = t->stack[t->top - 1];
	t->stack[t->top - 1] = temp;
	if (name != 'x')
		ft_printf("s%c\n", name);
}

void	sswap(t_stack *a, t_stack *b)
{
	int	temp_a;
	int	temp_b;

	if (a->top < 1 && b->top < 1)
		return ;
	temp_a = stk_peek(a, 1);
	temp_b = stk_peek(b, 1);
	a->stack[a->top] = a->stack[a->top - 1];
	b->stack[b->top] = b->stack[b->top - 1];
	a->stack[a->top - 1] = temp_a;
	b->stack[b->top - 1] = temp_b;
	ft_printf("ss\n");
}

void	rotate(t_stack *t, char name)
{
	int	i;
	int	top;

	if (t->top < 1)
		return ;
	i = t->top;
	top = stk_peek(t, 1);
	while (i != 0)
	{
		t->stack[i] = t->stack[i - 1];
		i--;
	}
	t->stack[0] = top;
	if (name != 'x')
		ft_printf("r%c\n", name);
}

void	rrotate(t_stack *a, t_stack *b)
{
	rotate(a, 'x');
	rotate(b, 'x');
	ft_printf("rr\n");
}

void	r_rotate(t_stack *t, char name)
{
	int	i;
	int	last;

	if (t->top < 1)
		return ;
	i = 0;
	last = t->stack[0];
	while (i < t->top)
	{
		t->stack[i] = t->stack[i + 1];
		i++;
	}
	t->stack[t->top] = last;
	if (name != 'x')
		ft_printf("rr%c\n", name);
}

void	r_rrotate(t_stack *a, t_stack *b)
{
	r_rotate(a, 'x');
	r_rotate(b, 'x');
	ft_printf("rrr\n");
}

void	push_x(t_stack *dst, t_stack *src, char name)
{
	if (stk_is_empty(*src))
		return ;
	stk_push(dst, stk_pop(src));
	ft_printf("p%c\n", name);
}
