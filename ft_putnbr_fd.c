/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:41:54 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 13:53:32 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    long    ln;

    ln = n;
    if(ln < 0)
        ft_putchar_fd('-', fd);
        ln = -ln;
    if (ln <= 9)
        ft_putnbr_fd(ln + '0', fd);
    if (ln > 9)
        {
            ft_putnbr_fd(ln / 10, fd);
            ft_putnbr_fd(ln % 10, fd);
        }
}