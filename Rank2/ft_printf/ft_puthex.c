/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 11:19:31 by sraiha            #+#    #+#             */
/*   Updated: 2024-12-07 11:19:31 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void    ft_put_hex(unsigned int num, size_t counter, char *base)
{
    char *str;

    str = ft_put_num_by_base(num, base);
    ft_putstr(str, counter);
    free(str);
}