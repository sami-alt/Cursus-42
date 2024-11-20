/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-20 10:46:36 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-20 10:46:36 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    const char *temp;

    temp = s;
    while (*temp)
        temp++;
    return (temp - s);
}

char    *ft_strjoin(const char *s1, const char *s2)
{   
    char *new_str;
    size_t i;
    size_t j;

    new_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!new_str)
        return (NULL);
    i = 0;
    while (s1[i]){
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[i]){
        new_str[i] = s2[j];
        j++;
        i++;
    }
    new_str[ft_strlen(s1) + ft_strlen(s2)] = 0;
    return (new_str);
}
  
char    *ft_strchr(char *s, int c)
{   
    if (!*s)
        return (NULL);
    while(*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if (*s == '\0')
        return ((char *)s);
    return (NULL);
}
