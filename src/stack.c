/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:20:33 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 11:02:51 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stk_push(t_stack *t, int n)
{
	t->stack[t->top + 1] = n;
	t->top++;
}

int	stk_pop(t_stack *t)
{
	return (t->stack[t->top--]);
}

int	stk_peek(t_stack *t, int pos)
{
	return (t->stack[t->top - (pos - 1)]);
}

int	stk_is_empty(t_stack t)
{
	return (t.top == -1);
}

t_stack	stk_new(int capacity)
{
	t_stack	t;
	int		*arr;

	arr = malloc(sizeof(int) * capacity);
	t.stack = arr;
	t.capacity = capacity;
	t.top = -1;
	return (t);
}
