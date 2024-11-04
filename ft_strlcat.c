/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:19:43 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 12:22:13 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t      ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t      i;
    size_t      dstlen;
    size_t      srclen;
    size_t      dstend;

    dstlen = ft_strlen(dst);
    srclen = ft_strlen(src);
    dstend = dstlen;
    i = 0;    

    while (*(src + i) != '\0')
    {
        *(dst + dstend) = *(src + i);
        dstend++;
        i++;
        if(dstend == size - 1)
            break;
    }
    *(dst + dstend) = '\0';

    return (dstlen + srclen);
}