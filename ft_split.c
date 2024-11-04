/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:08:50 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 15:54:45 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{   
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		else
		{
			s++;
		}
	}
	return (len);
}

char    **ft_split(const char *s, char c)
{
    char **res;
    size_t len;
    int i;

    i = 0;
    if (!s)
        return (0);
    res = malloc(sizeof(char *) * ft_len(s, c) + 1);
    if(!res)
        return (NULL);
    while(*s)
    {
        if (*s != c)
        {
            len = 0;
            while (*s && *s != c && ++len)
                s++;
            *res++ = ft_substr(s - len, 0, len);
            i++;
        }
        else
            ++s;
    }
    *res = '\0';
    return (res - i);
}

char ft_putchar(char *s)
{   
    while(*s)
        printf("%c", *s++);
}
int main(int argc, char **argv)
{
    char split[] = "asd/qew/ry";
    char **res;
    res = ft_split(split, '/');

    //printf("%s", *res);

    while(*res)
        ft_putchar(*res++);

    return (0);
}
