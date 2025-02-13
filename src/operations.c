/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:08:16 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/13 13:08:16 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void swap(t_stack *t)
{
    int temp;

    if (t->top < 1)
        return ;
    temp = t->stack[t->top];
    t->stack[t->top] = t->stack[t->top - 1];
    t->stack[t->top - 1] = temp;
}

void rotate(t_stack *t)
{
    int i;
    int top;

    if (t->top == 0)
        return ;
    i = t->top;
    top = t->stack[t->top];
    while (i != 0)
    {
        t->stack[i] = t->stack[i - 1];
        i--;
    }
    t->stack[0] = top; 
}

void r_rotate(t_stack *t)
{
    int i;
    int last;

    if (t->top == 0)
        return ;
    i = 0;
    last = t->stack[0];
    while (i < t->top)
    {
        t->stack[i] = t->stack[i + 1];
        i++;
    }
    t->stack[t->top] = last;
}

void push_x(t_stack *dst, t_stack *src)
{
    if (is_empty(*src))
        return ;
    push(dst, pop(src));
}

void print_2stacks(t_stack a, t_stack b)
{
    int i;

    ft_printf(" a \t b \n");
    if (a.top >= b.top)
        i = a.top;
    else
        i = b.top;
    while (i >= 0)
    {
        if (i > a.top)
        {
            ft_printf("   \t %d \n", b.stack[i]);
        }
        else if (i > b.top)
        {
            ft_printf(" %d  \t   \n", a.stack[i]);
        }
        else
        {
            ft_printf(" %d \t %d \n", a.stack[i], b.stack[i]);
        }
        i--;
    }
    ft_printf("----------\n");
}

void print_stack(t_stack t)
{
    int i;

    if (t.top == 0)
    {
        ft_printf("\n-----\n");
        return ;
    }
    i = t.top;
    while (i >= 0)
    {
        ft_printf("%d\n", t.stack[i]);
        i--;
    }
    ft_printf("\n-----\n");
}
