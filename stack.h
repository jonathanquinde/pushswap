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
#include "libft.h"

typedef struct s_stack
{
    size_t size;
    size_t max_size;
    int     *stack;
}               t_stack;

void push(t_stack *stack, int n);
int pop(t_stack *stack);
void swap(t_stack *stack);
void rotate(t_stack *stack);
void r_rotate(t_stack *stack);
void print_stack(t_stack t);