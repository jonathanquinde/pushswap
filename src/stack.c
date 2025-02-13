/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:20:33 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/11 21:20:33 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void push(t_stack *t, int n)
{
    t->stack[t->top + 1] = n;
    t->top++;
}

int pop(t_stack *t)
{
    return (t->stack[t->top--]);
}

int peek(t_stack *t)
{
    return (t->stack[t->top]);
}

int is_empty(t_stack t)
{
    return (t.top == -1);
}

int is_full(t_stack t)
{
    return (t.capacity == t.top + 1);
}
