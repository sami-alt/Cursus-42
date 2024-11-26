#include "libftprintf.h"

size_t  num_len(unsigned long nb, char *base)
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


char    *ft_put_num_by_base(unsigned long long num, char *base)
{   
    char *number;

    //len of num
    //base len 10 or 16
    //malloc char number
    //input numns to char number

    return (number);
} 