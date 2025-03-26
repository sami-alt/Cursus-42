/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:58:11 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/13 15:30:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int nbr, int *counter)
{
	char	*number;

	number = ft_put_num_by_base(nbr, DECIMAL);
	ft_putstr(number, counter);
	free(number);
}
