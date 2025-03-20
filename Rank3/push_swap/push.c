/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:44:53 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 13:22:55 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(piles_t *pile)
{
    int     i;

    if(pile->size_b)
    {
        pile->size_a++;
        i = pile->size_a;
        i--;
        while(--i > 0)
            pile->pile_a[i] = pile->pile_a[i - 1];
        pile->pile_a[0] = pile->pile_b[0];
        i = -1;
        pile->size_b--;
        while(++i < pile->size_a)
            pile->pile_b[i] = pile->pile_b[i + 1];
        ft_printf("pa\n");
    }
    else
        return ;    
}


void    push_b(piles_t *pile)
{
    int     i;
    
    if(pile->size_a)
    {
        pile->size_b++;
        i = pile->size_b;
        while(--i > 0)
            pile->pile_b[i] = pile->pile_b[i - 1];
        pile->pile_b[0] = pile->pile_a[0];
        i = -1;
        pile->size_a--;
        while(++i < pile->size_a)
            pile->pile_a[i] = pile->pile_a[i + 1];
        ft_printf("pb\n");
    }
    else
        return ;
    
}