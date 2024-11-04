/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-01 15:48:37 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-01 15:48:37 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    unsigned char      *temp;
    size_t              i;

    i = 0;
    temp = malloc(count * size);
    if (!temp)
        return (NULL);
    while (temp[i])
        temp [i++] = 0;
    return (temp);
}
