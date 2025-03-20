/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:08:41 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 13:49:12 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(piles_t *pile)
{
	int		temp;

	if(pile->size_a == 0 || pile->size_a == 1)
		return ;
	temp =  pile->pile_a[0];
	pile->pile_a[0] = pile->pile_a[1];
	pile->pile_a[1] = temp;
	ft_printf("sa\n");
}

void	swap_b(piles_t *pile)
{	
	int 	temp;
	if(pile->size_b == 0 || pile->size_b == 1)
		return ;
	temp =  pile->pile_b[0];
	pile->pile_b[0] = pile->pile_b[1];
	pile->pile_b[1] = temp;
	ft_printf("sa\n");
}

void	swap_s(piles_t *pile)
{
	int 	temp;
	if(pile->size_a == 0 || pile->size_a == 1 || pile->size_b == 0 || pile->size_b == 1)
		return ;
	temp =  pile->pile_a[0];
	pile->pile_a[0] = pile->pile_a[1];
	pile->pile_a[1] = temp;
	temp =  pile->pile_b[0];
	pile->pile_b[0] = pile->pile_b[1];
	pile->pile_b[1] = temp;
	ft_printf("ss\n");
}