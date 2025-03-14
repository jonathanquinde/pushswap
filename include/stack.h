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

void	stk_push(t_stack *t, int n);
int		stk_pop(t_stack *t);
int 	stk_peek(t_stack *t, int pos);
int 	stk_is_empty(t_stack t);
t_stack	stk_new(int capacity);