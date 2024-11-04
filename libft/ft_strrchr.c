/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-31 13:19:59 by sraiha            #+#    #+#             */
/*   Updated: 2024-10-31 13:19:59 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    signed int      len;
    unsigned char   found;

    len = ft_strlen(s);
    found = (char)c;
    while(len >= 0)
    {   
        if (s[len] == found)
            return ((char *) &s[len]);
        len--;
    }
    return (NULL);
}

int main()
{   
    char test[] = "abcdb";
    char *res; 

    res = ft_strrchr(test, '\0');
    if (res == NULL)
        printf("NULL");
    else if (*(res) == '\0')
        printf("terminator");
    else
        printf("%c", *(res));

    return (0);
}