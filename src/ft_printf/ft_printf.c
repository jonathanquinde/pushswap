/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:38:57 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/08 18:49:55 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion_specifiers(char word, va_list arguments);

int	ft_printf(char const *str, ...)
{
	int		i;
	int		sum;
	va_list	arguments;

	va_start(arguments, str);
	sum = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			sum += conversion_specifiers(str[++i], arguments);
		else
			sum += write(1, &str[i], 1);
		i++;
	}
	va_end(arguments);
	return (sum);
}

int	conversion_specifiers(char word, va_list arguments)
{
	size_t	sum;

	sum = 0;
	if (word == 'c')
		sum += put_char(va_arg(arguments, int));
	else if (word == 's')
		sum += put_str(va_arg(arguments, char *));
	else if (word == 'i' || word == 'd')
		sum += handle_negative(va_arg(arguments, int));
	else if (word == 'u')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_DEC, 10);
	else if (word == 'p')
		sum += put_pointer_adress(va_arg(arguments, void *));
	else if (word == 'x')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_HEX_MIN, 16);
	else if (word == 'X')
		sum += put_nbr_base(va_arg(arguments, unsigned int), BASE_HEX_MAY, 16);
	else if (word == '%')
		sum += write(1, "%%", 1);
	return (sum);
}
