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