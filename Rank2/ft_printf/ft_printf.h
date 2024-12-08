#ifndef LIBFTPRINT_H
# define LIBFTPRINT_H

#include <stdarg.h>
//#include <unistd.h>
#include <io.h> 
int     ft_printft(const char *, ...);
void    ft_putchar(int c, size_t counter);
void    ft_putstr(char *str, size_t counter);


# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"
# define DECIMAL "0123456789"

#endif