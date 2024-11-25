#include "ft_printf.h"

void     ft_putchar(int c, size_t *counter)
{
    write(1, &c, 1);
    *(counter)++;
}

void    ft_format(const char *c, size_t *counter){
    if (*c == 'c')
    {
        ft_putchar(va_arg(va, int), &counter);
    } else if (*c == 's')
    {
        ft_putstr(va_arg(va, char *), &counter);
    } else if (*c == 'p')
    {
        ft_putptr(va_arg(va, void *), &counter);
    } else if (*c == 'd' && c == 'i')    
    {
        ft_putnbr(va_arg(va, int), &counter);
    } else if *(*c == 'u')
    {
        ft_printunsigned(va_arg(va, unsigned int), &counter);
    } else if (*c == 'x')
    {
        ft_printhex(va_arg(va, unsigned int), %counter, HEX_LOWER);
    }  else if (*c == 'X')
    {
        ft_printhex(va_arg(va, unsigned int), HEX_UPPER);
    } else if (*c == '%')
    {
        ft_printchar(va_arg(va, char *), &counter);
    }
}

int     ft_printf(const chat *string, ...)
{   
    va_lits     va;
    int         counter;

    va_start(va, string);
    i = 0;
    while (*string)
    {
        if (*string == '%')
        {   
            string++;
            ft_format(va, *string, &counter);
        } 
        else 
        {
           ft_printchar(*str, &counter);
        }
        string++;
    }
    va_end(va);
    return (print_len);
}