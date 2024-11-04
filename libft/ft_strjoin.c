/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-02 11:04:25 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-02 11:04:25 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(const char* s1, const char *s2)
{
    char *res;
    size_t size;

    size = ft_strlen(s1) + ft_strlen(s2) + 1;

    res = malloc(sizeof(char) * size);
    if (!res)
        return (NULL);
    while(*s1)
        *res++=*s1++;
    while(*s2)
        *res++=*s2++;
    *res = '\0';
    res = res - size + 1;
    return (res);
}
