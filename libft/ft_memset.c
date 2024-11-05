/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:38:01 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 12:22:01 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    size_t          i;
    char            *temp;

    temp = s;
    i = 0;

    if(!s)
        return (NULL);

    while(i < n)
    {
        *temp =  c;
        temp++;
        i++;
    }
    return (s);
}