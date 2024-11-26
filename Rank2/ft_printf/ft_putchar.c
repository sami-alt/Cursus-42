#include "libftprintf.h"

void     ft_putchar(int c, size_t *counter)
{   
    write(1, &c, 1);
    *(counter)++;
}