/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countelements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:09:42 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/18 15:15:15 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_elements(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
	{
		count++;
	}
	return (count);
}
