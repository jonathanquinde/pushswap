/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:38:38 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/08 12:23:44 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_char(char c)
{
	return (write(1, &c, 1));
}

int	put_str(char *str)
{
	int	sum;

	if (str == NULL)
		return (write(1, "(null)", 6));
	sum = 0;
	while (*str)
		sum += write(1, str++, 1);
	return (sum);
}
