/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 14:45:53 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-01 14:45:53 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *memchr(const void *s, int c, size_t n)
{
    unsigned char cc;
    size_t i;
    const char *temp;

    temp = s;
    cc = (unsigned char)c;
    i = 0;
    while (i < n)
    {
        if(*(unsigned char *)temp == cc)
            return ((void *)s);
        temp++;
    }
    return (NULL);
}