/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:03:00 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/17 21:41:34 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	*sorted_array(int *arr, int size, int top)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * (size));
	if (!copy)
		return (0);
	i = 0;
	while (i < size)
	{
		copy[i] = arr[top - i];
		i++;
	}
	i = 1;
	for (int i = 1; i < size; i++)
	{
		int key = copy[i];
		int j = i - 1;
		while (j >= 0 && copy[j] > key) {
			copy[j + 1] = copy[j];
			j--;
		}
		copy[j + 1] = key;
	}
	return (copy);
}


int	find_median(t_stack *a, int range)
{
	int	*copy;
	int	median;

	copy = sorted_array(a->stack, range, a->top);
	if (range % 2 == 1)
		median = copy[range / 2];
	else
		median = floor((copy[range / 2 + 1] + copy[range / 2]) / (double)2);
	free(copy);
	return (median);
}

int	is_sorted(int *arr, int range, int top)
{
	int	i;

	if (range < 2 || top < 1)
		return (1);
	i = top;
	while (i > top - range + 1)
	{
		if (arr[i] > arr[i - 1])  
			return (0);
		i--;
	}
	return (1);
}

int	is_sorted_rev(int *arr, int range, int top)
{
	int	i;

	if (range < 2 || top < 1)
		return (1);
	i = top;
	while (i > top - range + 1)
	{
		if (arr[i] < arr[i - 1])
			return (0);
		i--;
	}
	return (1);
}
