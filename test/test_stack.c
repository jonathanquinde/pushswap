/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:20:26 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/11 21:20:26 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../stack.h"

int main(void)
{
    t_stack stack;
    int arr[] = {1, 2, 3, 4, 5};

    stack.stack = arr;
    stack.max_size = 5;
    stack.size = 5;
    print_stack(stack);

    //Swap
    ft_putstr_fd("Swap:\n", 1);
    swap(&stack);
    print_stack(stack);

    //Rotate
    ft_putstr_fd("Rotate:\n", 1);
    rotate(&stack);
    print_stack(stack);

    //Pop
    ft_putstr_fd("Pop:\n", 1);
    int n = pop(&stack);
    print_stack(stack);

    //R-Rotate
    ft_putstr_fd("R-Rotate:\n", 1);
    r_rotate(&stack);
    print_stack(stack);

    //Push
    ft_putstr_fd("Push:\n", 1);
    push(&stack, n);
    print_stack(stack);
}