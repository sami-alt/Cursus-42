/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:55:30 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/09 13:59:48 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, size_t *counter)
{
	long	nb;

	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', counter);
		ft_putnbr(nb, counter);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10, counter);
		ft_putchar('0' + nb % 10, counter);
	}
}
