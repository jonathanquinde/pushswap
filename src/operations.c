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

void swap(t_stack *t, char name)
{
    int temp;

    if (t->top < 1)
        return ;
    temp = t->stack[t->top];
    t->stack[t->top] = t->stack[t->top - 1];
    t->stack[t->top - 1] = temp;
    ft_printf("s%c\n", name);
}

void sswap(t_stack *a, t_stack *b)
{
    int temp_a;
    int temp_b;

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

void rotate(t_stack *t, char name)
{
    int i;
    int top;

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
    ft_printf("r%c\n", name);
}

void r_rotate(t_stack *t, char name)
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
    ft_printf("rr%c\n", name);
}

void push_x(t_stack *dst, t_stack *src, char name)
{
    if (stk_is_empty(*src))
        return ;
    stk_push(dst, stk_pop(src));
    ft_printf("p%c\n", name);
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
