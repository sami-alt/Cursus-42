/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:45:49 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 12:22:29 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    char        *res;
    size_t      i;

    i = 0;
    if (!s)
        return (NULL);
    if (start > ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    res = malloc(sizeof(char) * len + 1);
    if (!res)
        return (NULL);

    while(i < len)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = '\0';
    return (res);
}
