/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:02:49 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/18 16:12:12 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_number(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate_and_convert_split(t_stack *a, char **arg, int i)
{
	long	num;

	if (!is_valid_number(arg[i]))
	{
		write(STDERR_FILENO, "Error\n", 7);
		stk_free(a);
		arr_arr_free((void ***)&arg, ft_count_elements(arg));
		exit(EXIT_FAILURE);
	}
	num = ft_atol(arg[i]);
	if (num < INT_MIN || num > INT_MAX)
	{
		write(STDERR_FILENO, "Error\n", 7);
		stk_free(a);
		arr_arr_free((void ***)&arg, ft_count_elements(arg));
		exit(EXIT_FAILURE);
	}
	stk_push(a, (int)num);
}

void	validate_and_convert(t_stack *a, char *arg)
{
	long	num;

	if (!is_valid_number(arg))
	{
		write(STDERR_FILENO, "Error\n", 7);
		stk_free(a);
		exit(EXIT_FAILURE);
	}
	num = ft_atol(arg);
	if (num < INT_MIN || num > INT_MAX)
	{
		write(STDERR_FILENO, "Error\n", 7);
		stk_free(a);
		exit(EXIT_FAILURE);
	}
	stk_push(a, (int)num);
}

void	parse_input(t_stack **a, int argc, char **argv)
{
	int		i;
	char	**split_args;

	if (argc < 2)
		write(STDERR_FILENO, "Error\n", 7);
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		split_args = ft_split(argv[1], ' ');
		i = ft_count_elements(split_args) - 1;
		*a = stk_new(i + 1);
		while (i >= 0)
		{
			validate_and_convert_split(*a, split_args, i);
			i--;
		}
		arr_arr_free((void ***)&split_args, ft_count_elements(split_args));
	}
	else
	{
		i = argc -1;
		*a = stk_new(i);
		while (i > 0)
			validate_and_convert(*a, argv[i--]);
	}
	if (has_duplicates((*a)->stack, (*a)->capacity))
	{
		write(STDERR_FILENO, "Error\n", 7);
		stk_free(*a);
		exit(EXIT_FAILURE);
	}
}
