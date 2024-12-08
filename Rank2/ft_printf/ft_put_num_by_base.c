/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_by_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-07 11:20:26 by sraiha            #+#    #+#             */
/*   Updated: 2024-12-07 11:20:26 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */


#include "libftprintf.h"

int     ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;

    return (len);
}



size_t  ft_num_len(unsigned long nb, char *base)
{
    unsigned long long  len;
    size_t              base_len;

    base_len = ft_strlen(base);
    nb = 1;    
    while (nb >= base_len)
    {
        nb /= base_len;
        len++;
    }
    return (len);
}   

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;

    ptr =  (unsigned char)s;
    while (n > 0)
    {
        *ptr = 0;
        ptr++;
        n--;
    }
}

void    *ft_calloc(size_t count, size_t size)
{   
    void    *mem;

    mem = malloc(count * size);
    if (!mem)
        return (NULL);
    ft_bzero(mem, count * size);
    return (mem);
}

char    *ft_put_num_by_base(unsigned long long num, char *base)
{   
    char    *number;
    size_t  num_len;
    size_t  base_size;
    
    num_len = ft_num_len(num, base);
    base_size = ft_strlen(base);

    number = ft_calloc((num_len + 1), sizeof(char)); 
    
    while (num_len)
        num--;
        number[num_len] = base[num % base_size];
        num /= base_size; 

    return (number);
} 