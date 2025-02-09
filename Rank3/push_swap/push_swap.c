/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 11:47:34 by sraiha            #+#    #+#             */
/*   Updated: 2025-01-13 11:47:34 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>


void    push_swap(char *input)
{
    while (*input)
    {
        printf("%c", *input);
        input++;
    }
}

int     main(int argc, char **argv)
{   
    *argv += 1;
    push_swap(*argv);
    return (0);
}