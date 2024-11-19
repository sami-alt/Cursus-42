#ifndef GET_NEST_LINE_H 
# define GET_NEST_LINE_H

#include <stdlib.h>
#include <io.h>// <unistd.h>

#define MAX_FD 1024

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);


#endif