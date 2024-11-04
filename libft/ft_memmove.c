/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:01:09 by sraiha            #+#    #+#             */
/*   Updated: 2024/10/29 14:52:09 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dest, const void  *src, size_t n)
{   
    char *cdest;
    const char *csrc;

    cdest = (char *)dest;
    csrc = (char *)src;
    if(!dest && !src)
        return (NULL);
    if(dest <= src)
    {
        while(n--)
            *cdest++ = *csrc++;
    }
    else if (dest > src)
    {
        cdest += n -1;
        csrc +=  n - 1;
        while(n--)
        {
            *cdest-- = *csrc--;
        }
    }
    return (dest);
}