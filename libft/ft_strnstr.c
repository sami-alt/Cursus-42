/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:05:16 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 14:37:51 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{   
    size_t      i;
    const char *tempHaystack;
    const char *tempNeedle;

    i = 0;
    if (!*needle)
        return ((char *)haystack);
    if(ft_strlen(needle) > len || !*haystack)
        return (NULL);
    while(i++ < len && *haystack)
    {
        tempHaystack = haystack;
        tempNeedle = needle;
        while (*tempNeedle && *tempHaystack == *tempNeedle && i < len)
        {
            tempHaystack++;
            tempNeedle++;
            i++;
        }
        if (!*tempNeedle)
            return ((char *)haystack);
        haystack++;
    }
    return (NULL);
}

