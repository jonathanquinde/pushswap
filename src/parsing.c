/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:02:49 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/06 16:02:49 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// Checks if a string is a valid integer
int is_valid_number(char *str)
{
    if (*str == '-' || *str == '+') // Allow negative/positive signs
        str++;
    if (*str == '\0') // Must have digits after sign
        return 0;
    while (*str)
    {
        if (!ft_isdigit(*str))
            return (0); // Contains non-digit character
        str++;
    }
    return (1);
}

// Checks for duplicates in an array
int has_duplicates(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
                return 1; // Duplicate found
        }
    }
    return 0;
}

// Parses command-line arguments into stack `a`
void parse_input(t_stack *a, int argc, char **argv)
{
    if (argc < 2) // No numbers provided
    {
		write(STDERR_FILENO, "Error\nNumero de parametros erroneo\n", 36);
        exit(EXIT_FAILURE);
    }
	*a = stk_new(argc - 1);
    if (a->stack == NULL)
    {
		write(STDERR_FILENO, "Error\nAlocacion de memoria fallida\n", 36);
        exit(EXIT_FAILURE);
    }

    // Convert input strings to integers
    for (int i = argc - 1; i > 0; i--)
    {
        if (!is_valid_number(argv[i])) // Validate input
        {
			write(STDERR_FILENO, "Error\nNumero invalido\n", 23);
            free(a->stack);
            exit(EXIT_FAILURE);
        }
        long num = atol(argv[i]); // Convert string to number
        if (num < INT_MIN || num > INT_MAX) // Ensure it's within int range
        {
			write(STDERR_FILENO, "Error\nNumero fuera de rango\n", 23);
            free(a->stack);
            exit(EXIT_FAILURE);
        }
		stk_push(a, (int)num);
    }

    // Check for duplicates
    if (has_duplicates(a->stack, a->capacity))
    {
		write(STDERR_FILENO, "Error\nNumero duplicado\n", 24);
        free(a->stack);
        exit(EXIT_FAILURE);
    }
}
