/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha.student@hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-03 11:14:11 by sraiha            #+#    #+#             */
/*   Updated: 2024-11-03 11:14:11 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*)){
    unsigned int    i;

    i = 0;
    while(s[i])
        (*f)(i, &s[i++]);
}

void f(unsigned int i, char* c){  *c + 1;}

int main()
{
    char *test = "abcd";
    ft_striteri(test, f);

    printf("%s", test);
}