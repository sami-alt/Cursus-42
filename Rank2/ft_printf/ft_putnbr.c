/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:55:30 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/13 15:30:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *counter)
{
	if (nbr == -2147483648)
	{
		ft_putnbr(nbr / 10, counter);
		ft_putchar('8', counter);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', counter);
		ft_putnbr(nbr, counter);
	}
	else
	{
		if (nbr > 9)
			ft_putnbr(nbr / 10, counter);
		ft_putchar('0' + nbr % 10, counter);
	}
}
