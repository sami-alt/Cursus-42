/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:58:14 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/10 13:12:23 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, size_t *counter)
{
	unsigned long	ptr_adr;
	char			*adr;

	ptr_adr = (unsigned long)ptr;
	ft_putstr("0x", counter);
	adr = ft_put_num_by_base(ptr_adr, HEX_LOWER);
	ft_putstr(adr, counter);
	free(adr);
}
