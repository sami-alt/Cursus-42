/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:04 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 15:24:23 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_memcmp(const void *s1, const void *s2, size_t n)
{   
    size_t i;
    const unsigned char *stemp1;
    const unsigned char *stemp2;

    stemp1 = s1;
    stemp2 = s2;
    i = 0;
    while(i < n && *(stemp1 + i) && *(stemp2 + i))
    {
        if (*(unsigned char *)(stemp1 + i) != *(unsigned char*)(stemp2 + i))
            return (*(unsigned char *)(stemp1 + i) - *(unsigned char *)(stemp2 + i));
        i++;
    }
    return (0);
}
