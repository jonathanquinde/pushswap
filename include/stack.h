/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:20:30 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/11 21:20:30 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_stack
{
    int capacity;
    int top;
    int     *stack;
}               t_stack;

void push(t_stack *t, int n);
int pop(t_stack *t);
int peek(t_stack *t);
int is_empty(t_stack t);
int is_full(t_stack t);