/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 11:13:44 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-03 11:13:44 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  numberlen(int n)
{
    int len;

    len = 0;
    if (n <= 0)
        len++;
    while(n)
    {
        n = n / 10;
        len++;
    }
    return (len);
} 

char *ft_itoa(int n){
    char *number;
    int len;
    char *digit = "0123456789";
    
    len = numberlen(n);
    number = malloc(sizeof(char *) * len + 1);
    if(!number)
        return (NULL);
    number[0] = 0;
    if (n == 0)
        number[0] = '0';
    if (n < 0)
        number[0] = '-';
    number[len] = '\0';
    while(n)
    {
        if (n > 0)
            number[--len] = digit[ n % 10];
        else
            number[--len] = digit[n % 10 * -1];
        n /= 10;
    }   

    return (number);
}

int  main(){
    char *num = ft_itoa(12345678);

    printf("%s", num);


}