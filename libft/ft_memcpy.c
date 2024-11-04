/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:29:18 by sraiha            #+#    #+#             */
/*   Updated: 2024/10/30 12:41:19 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t      i;
    const char *temp;
    char *ret;

    ret = (char *)dest;
    temp = (char *)src;
    i = 0;
    while(n--)
    {
        *ret++ = *temp++;
        i++;
    }
    return (dest);
}
#include <stdio.h> 
#include <string.h> 

int main() 
{ 
    char csrc[100] = "Geeksfor"; 
    memcpy(csrc + 5, csrc, strlen(csrc) + 1); 
    printf("%s", csrc); 
    return 0; 
}