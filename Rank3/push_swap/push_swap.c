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


void    push_swap(char *av)
{
    piles_t     pile;
    int         size;
    int         i;

    i = 0;
    size = push_swap_strlen(&av);
    pile.pile_a = ft_calloc(size, sizeof(int));
    if (!pile.pile_a)
        return ;
    pile.size_a = size;
    pile.pile_b = ft_calloc(size, sizeof(int));
    if (!pile.pile_b)
    {
        free(pile.pile_a);
        return ;
    }
    pile.size_b = 0;
    while (i++ < size)
        pile.pile_a[i] = push_swap_atoi(&av[i], pile.pile_a);
    check_for_doubles(pile, size);
    sort(pile.pile_a, size);
    free(pile.pile_a);
    free(pile.pile_b);
}

int     main(int ac, char **av)
{   
    if (ac > 1)
    {
        av++;
        if (ac == 2)
            av = ft_split(*av, ' ');
        push_swap(av);
        return (0);
    }
    return (0);
}