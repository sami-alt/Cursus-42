#include "bsq.h"

int main(int argc, char **argv)
{   
    if (argc > 1)
    {
        argv++;
        while (*argv)
        {   
            bsq(*argv);   
            argv++;
        }
    }
    return (0);
}
