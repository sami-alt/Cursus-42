/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:22 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 13:22:53 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(piles_t *pile)
{   
    int     temp;
    int     i;

    if (pile->size_a == 0 || pile->size_a == 1)
        return ;

    i = 0;
    temp = pile->pile_b[i];
    i++;
    while(i < pile->size_b)
    {
        pile->pile_b[i - 1] = pile->pile_b[i];
        i++;
    }
    pile->pile_b[i] = temp;
    ft_printf("ra\n");
}

void    rotate_b(piles_t *pile)
{
    int     temp;
    int     i;
    if (pile->size_b == 0 || pile->size_b == 1)
        return ;   
    i = 0;
    temp = pile->pile_b[i];
    i++;
    while(i < pile->size_b)
    {
        pile->pile_b[i  - 1] = pile->pile_b[i];
        i++;
    }
    pile->pile_b[i] = temp;
    ft_printf("rb\n");
}

void    rotate_r(piles_t *pile)
{
    int     temp;
    int     i;

    if (pile->pile_a == 0 || pile->pile_a == 1 || pile->pile_b == 0 || pile->pile_b == 1)
        return ;
    i = 0;
    temp = pile->pile_a[i];
    i++;
    while(i < pile->size_a)
    {
        pile->pile_a[i - 1] = pile->pile_a[i];
        i++;
    }
    pile->pile_a[i] = temp;
    i = 0;
    temp = pile->pile_b[i];
    i++;
    while(i < pile->size_b)
    {
        pile->pile_b[i - 1] = pile->pile_b[i];
        i++;
    }
    pile->pile_b[i] = temp;
    ft_printf("rr\n");
}

