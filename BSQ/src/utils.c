#include "bsq.h"

int ft_atoi(char *numbers)
{   
    int result;
    int index;
    result = 0;
    index =  0;
    while (numbers[index])
    {   
        if(numbers[index] >= '0' && numbers[index] <= '9')
        {   
            result = result * 10  + numbers[index] - '0';
        }
        index++;
    }
    return (result); 
}

void freeMem(char **map, int rows)
{
    int i;

    i = 0;
    while(i < rows)
    {
        free(map[i++]);
    }
    free(map);
}