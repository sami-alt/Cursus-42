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

#include "../include/push_swap.h"

void    push_swap(char **av)
{
    piles_t     pile;
    int         size;
    int         i;

    i = -1;
    size = push_swap_strlen(av);
    pile.pile_a = malloc(size * sizeof(int));
    if (!pile.pile_a)
        return ;
    pile.size_a = size;
    pile.pile_b = malloc(size * sizeof(int));
    if (!pile.pile_b)
    {
        free(pile.pile_a);
        return ;
    }
    pile.size_b = 0;
    while (++i < size)
        pile.pile_a[i] = push_swap_atoi(av[i], pile.pile_a);
    check_for_doubles(pile.pile_a, size);
    sort(&pile, size);
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