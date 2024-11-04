/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 15:06:04 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-01 15:06:04 by sraiha           ###   ########.fi       */
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

int main()
{   
    char test1[] = "abcdef";
    char test2[] = "abcdef";
    int res;

    res = ft_memcmp(test1, test2, 7);

    printf("%d", res);

    return (0);
}