/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:58:14 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/13 16:52:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int *counter)
{
	uintptr_t		ptr_adr;
	char			*adr;
	if (ptr){
		ptr_adr = (uintptr_t)ptr;
		ft_putstr("0x", counter);
		adr = ft_put_num_by_base(ptr_adr, HEX_LOWER);
		ft_putstr(adr, counter);
		free(adr);
	}
	else
		ft_putstr("(nil)", counter);
}
