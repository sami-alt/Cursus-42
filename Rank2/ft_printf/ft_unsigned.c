#include "libftprintf.h"

void    ft_putunsigned(unsigned int nbr, size_t *counter)
{
    char *number;
    ft_put_num_by_base(number, DECIMAL);
    ft_putstr(number, counter);
    free(number);
}