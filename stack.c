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

void push(t_stack *stack, int n)
{
    if (stack->size == stack->max_size)
        return ;
    stack->stack[stack->size] = n;
    stack->size++;
}

int pop(t_stack *stack)
{
    if (stack->size == 0)
        return -1;
    return (stack->stack[--stack->size]);
}
void swap(t_stack *t)
{
    int temp;

    if (t->size < 2)
        return ;
    temp = t->stack[t->size - 1];
    t->stack[t->size - 1] = t->stack[t->size - 2];
    t->stack[t->size - 2] = temp;
}

void rotate(t_stack *t)
{
    size_t i;
    int top;

    if (t->size < 2)
        return ;
    i = t->size - 1;
    top = t->stack[t->size - 1];
    while (i != 0)
    {
        t->stack[i] = t->stack[i - 1];
        i--;
    }
    t->stack[0] = top; 
}
void r_rotate(t_stack *t)
{
    size_t i;
    int last;

    if (t->size < 2)
        return ;
    i = 0;
    last = t->stack[0];
    while (i < t->size)
    {
        t->stack[i] = t->stack[i + 1];
        i++;
    }
    t->stack[t->size - 1] = last;
}

void print_stack(t_stack t)
{
    size_t i;

    if (t.size == 0)
    {
        ft_putstr_fd("-----\n", 1);
        return ;
    }
    i = t.size - 1;
    while (i != 0)
    {
        ft_putnbr_fd(t.stack[i], 1);
        ft_putchar_fd('\n', 1);
        i--;
    }
    ft_putnbr_fd(t.stack[i], 1);
    ft_putchar_fd('\n', 1);
    ft_putstr_fd("-----\n", 1);
}
