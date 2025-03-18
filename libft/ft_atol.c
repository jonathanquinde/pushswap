/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:21:22 by jquinde-          #+#    #+#             */
/*   Updated: 2025/03/18 15:22:13 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *ntpr)
{
	int		sign;
	long	num;

	num = 0;
	if (ntpr == NULL)
		return (num);
	while (*ntpr == ' ' || (*ntpr >= '\t' && *ntpr <= '\r'))
		ntpr++;
	sign = 1;
	if (*ntpr == '+' || *ntpr == '-')
	{
		if (*ntpr == '-')
			sign = -1;
		ntpr++;
	}
	while (ft_isdigit(*ntpr))
	{
		num = num * 10 + (*ntpr - '0');
		ntpr++;
	}
	return (num * sign);
}
