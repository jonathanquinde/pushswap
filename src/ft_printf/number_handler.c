/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquinde- < jquinde-@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:02:15 by jquinde-          #+#    #+#             */
/*   Updated: 2024/11/08 14:42:31 by jquinde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	put_nbr_base(unsigned long num, char *base, size_t len)
{
	int	sum;

	sum = 0;
	if (num >= len)
	{
		sum += put_nbr_base(num / len, base, len);
	}
	sum += write (1, &base[num % len], 1);
	return (sum);
}

int	put_pointer_adress(void *ptr)
{
	int	sum;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	sum = 0;
	sum += write(1, "0x", 2);
	sum += put_nbr_base((unsigned long) ptr, BASE_HEX_MIN, 16);
	return (sum);
}

int	handle_negative(int num)
{
	int	sum;

	if (num >= 0)
		return (put_nbr_base(num, BASE_DEC, 10));
	if (num == -2147483648)
		return (put_str("-2147483648"));
	sum = 0;
	sum += put_char('-');
	sum += put_nbr_base(-num, BASE_DEC, 10);
	return (sum);
}
