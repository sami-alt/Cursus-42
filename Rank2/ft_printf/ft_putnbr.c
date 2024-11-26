#include "libftprintf.h"

void    ft_putnbr(int nbr, size_t *counter)
{
    long nb;
    nb = nbr;

    if (nb < 0)
    {   
        nb *=  -1;
        ft_putchar('-', counter);
        ft_putnbr(nb, counter);
    } else 
    {
    if (nb > 9)
        ft_putnbr(nb / 10, counter);
    ft_putchar('0' + nb % 10, counter);
    }
}