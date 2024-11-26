#include "libftprintf.h"

void    ft_putptr(void *ptr, size_t counter)
{
    unsigned long ptr_adr;
    char adr;

    ft_putptr("0x", counter);
    ptr_adr = (unsigned long)ptr;
    adr = ft_put_num_by_base(ptr_adr ,HEX_LOWER);
    ft_putstr(adr, counter);
    free(adr);
}