/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:26 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/11 15:17:49 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_format(va_list va, char *string, size_t *counter)
{	
	if (*string == 'c')
		ft_putchar(va_arg(va, int), counter);
	else if (*string == 's')
		ft_putstr(va_arg(va, char *), counter);
	else if (*string == 'p')
		ft_putptr(va_arg(va, void *), counter);
	else if (*string == 'd' || *string == 'i')
		ft_putnbr(va_arg(va, int), counter);
	else if (*string == 'u')
		ft_putunsigned(va_arg(va, unsigned int), counter);
	else if (*string == 'x')
		ft_puthex(va_arg(va, unsigned int), counter, HEX_LOWER);
	else if (*string == 'X')
		ft_puthex(va_arg(va, unsigned int), counter, HEX_UPPER);
	else if (*string == '%')
		ft_putchar(*string, counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	counter;

	if (!format)
		return (-1);
	counter = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(va, (char *)format, &counter);
		}
		else
			ft_putchar(*format, &counter);
		format++;
	}
	va_end(va);
	return (counter);
}
