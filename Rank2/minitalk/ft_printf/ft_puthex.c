/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:19:31 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/13 15:30:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, int *counter, char *base)
{
	char	*str;

	str = ft_put_num_by_base(num, base);
	ft_putstr(str, counter);
	free(str);
}
