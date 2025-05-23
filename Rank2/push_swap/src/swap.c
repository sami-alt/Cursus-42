/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:08:41 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/25 15:01:56 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_piles *pile)
{
	int	tmp;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	tmp = 0;
	tmp = pile->pile_a[0];
	pile->pile_a[0] = pile->pile_a[1];
	pile->pile_a[1] = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_piles *pile)
{
	int	tmp;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	tmp = 0;
	tmp = pile->pile_b[0];
	pile->pile_b[0] = pile->pile_b[1];
	pile->pile_b[1] = tmp;
	ft_printf("sb\n");
}

void	swap_s(t_piles *pile)
{
	int		tmp;

	if (pile->size_a == 0 || pile->size_a == 1 || (pile->size_b == 0
			|| pile->size_b == 1))
		return ;
	tmp = 0;
	tmp = pile->pile_a[0];
	pile->pile_a[0] = pile->pile_a[1];
	pile->pile_a[1] = tmp;
	tmp = pile->pile_b[0];
	pile->pile_b[0] = pile->pile_b[1];
	pile->pile_b[1] = tmp;
	ft_printf("ss\n");
}
