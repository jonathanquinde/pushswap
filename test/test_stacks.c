/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:24:23 by jquinde-          #+#    #+#             */
/*   Updated: 2025/02/13 17:24:23 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int main(void)
{
    t_stack a;
    t_stack b;
    int arr[] = {2, 5, 3, 1, 7, 9};
    int arr2[6];
    char operation;
    char stack;

    a.capacity = 6;
    a.stack = arr;
    a.top = 5;
    b.capacity = 6;
    b.stack = arr2;
    b.top = -1;

    ft_printf("Bienvenido a tu push_swap simulator!!\nA continuacion se te mostraran dos stacks y las operaciones correspondientes. Ej: 1 b\n");
    ft_printf("Seleccione una operacion y el stack.\n\n");
    while (1)
    {
        print_2stacks(a, b);
        ft_printf("Operaciones: (1) Swap, (2) Rotate, (3) R-Rotate, (4) Push, (5) Sswap, (6) RRotate, (7) R-Rrotate, (q) Salir\n");
        ft_printf("----------\n");
        ft_printf("Input: ");
        scanf(" %c", &operation);
        if (operation == 'q')
            break;
        scanf(" %c", &stack);
        ft_printf("----------\n");

        t_stack *selected_stack = (stack == 'a') ? &a : &b;

        switch (operation)
        {
            case '1':
                swap(selected_stack);
                break;
            case '2':
                rotate(selected_stack);
                break;
            case '3':
                r_rotate(selected_stack);
                break;
            case '4':
                push_x((stack == 'a') ? &a : &b, (stack == 'a') ? &b : &a);
                break;
            case '5':
                swap(&a);
                swap(&b);
                break;
            case '6':
                rotate(&a);
                rotate(&b);
                break;
            case '7':
                r_rotate(&a);
                r_rotate(&b);
                break;
            default:
                printf("Operación inválida\n");
        }
    }
}