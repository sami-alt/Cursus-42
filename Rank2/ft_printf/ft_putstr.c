#include "libftprintf.h"

void    ft_putstr(char *str, size_t *counter)
{
    if (!str)
        return (NULL);
    while(*str)
        ft_putchar(*str++, counter);

}