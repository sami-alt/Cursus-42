/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:23:16 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 13:31:03 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(piles_t *pile)
{
	int		temp;
	int 	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = pile->size_a - 1;
	temp = pile->pile_a[i];
	while(i)
	{
		pile->pile_a[i] = pile->pile_a[i - 1];
		i--;
	}
	pile->pile_a[i] = temp;
	ft_printf("rra\n");

}

void	reverse_rotate_b(piles_t *pile)
{
	int		temp;
	int 	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = pile->size_b - 1;
	temp = pile->pile_b[i];
	while(i)
	{
		pile->pile_b[i] = pile->pile_b[i - 1];
		i--;
	}
	pile->pile_b[i] = temp;
	ft_printf("rrb\n");

}

void	reverse_rotate_r(piles_t *pile)
{
	int		temp;
	int 	i;
	if(pile->size_b == 0 || pile->size_b == 1 || pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = pile->size_a - 1;
	temp = pile->pile_a[i];
	while(i)
	{
		pile->pile_a[i] = pile->pile_a[i - 1];
		i--;
	}
	pile->pile_a[i] = temp;	
	i = pile->size_b - 1;
	temp = pile->pile_b[i];
	while(i)
	{
		pile->pile_b[i] = pile->pile_b[i - 1];
		i--;
	}
	pile->pile_b[i] = temp;
	ft_printf("rrr\n");
}