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
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char    *ft_strjoin(const char *s1, const char *s2)
{   
    char *new_str;
    size_t i;
    size_t j;
    size_t  total;

    total = ft_strlen(s1) + ft_strlen(s2);
    new_str = malloc(sizeof(char) * (total + 1));
    if (!new_str || !s1 || !s2)
        return (NULL);
    i = 0;
    while (s1[i]){
        new_str[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j]){
        new_str[i] = s2[j];
        j++;
        i++;
    }
    new_str[total] = 0;
    return (new_str);
}
  
char    *ft_strchr(char *s, int c)
{   
    char    *str;

    str = (char *)s;
    while (*str != c && *str != 0)
        str++;
    if (*str == c)
        return (str);
    else
        return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;

	res = malloc(size * count);
	if (!res)
		return (NULL);
	ft_bzero(res, size * count);
	return (res);
}