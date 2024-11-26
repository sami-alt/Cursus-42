#include "libftprintf.h"



void    ft_format(va_list va, char *string,size_t *counter){
    if (*string== 'c')
    {
        ft_putchar(va_arg(va, int), &counter);
    } else if (*string== 's')
    {
        ft_putstr(va_arg(va, char *), &counter);
    } else if (*string== 'p')
    {
        ft_putptr(va_arg(va, void *), &counter);
    } else if (*string== 'd' && string== 'i')    
    {
        ft_putnbr(va_arg(va, int), &counter);
    } else if (*string== 'u')
    {
        ft_putunsigned(va_arg(va, unsigned int), &counter);
    } else if (*string== 'x')
    {
        ft_puthex(va_arg(va, unsigned int), &counter, HEX_LOWER);
    }  else if (*string== 'X')
    {
        ft_puthex(va_arg(va, unsigned int), HEX_UPPER);
    } else if (*string== '%')
    {
        ft_putchar(va_arg(va, char *), &counter);
    }
}

int     ft_printf(const char *string, ...)
{   
    va_list     va;
    size_t         counter;

    va_start(va, string);
    while (*string)
    {
        if (*string == '%')
        {   
            string++;
            ft_format(va, *string, &counter);
        } 
        else 
        {
           ft_printchar(*string, &counter);
        }
        string++;
    }
    va_end(va);
    return (counter);
}