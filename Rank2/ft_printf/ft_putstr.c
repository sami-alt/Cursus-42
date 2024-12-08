#include "libftprintf.h"

void    ft_putstr(char *str, size_t *counter)
{
    if (!str)
        str = "(null)";
    while(*str)
        ft_putchar(*str++, counter);

}