/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:23:16 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/25 14:59:15 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = pile->size_a - 1;
	tmp = pile->pile_a[i];
	while (i)
	{
		pile->pile_a[i] = pile->pile_a[i - 1];
		i--;
	}
	pile->pile_a[i] = tmp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = pile->size_b - 1;
	tmp = pile->pile_b[i];
	while (i)
	{
		pile->pile_b[i] = pile->pile_b[i - 1];
		i--;
	}
	pile->pile_b[i] = tmp;
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_piles *pile)
{
	int		tmp;
	int		i;

	if (pile->size_a == 0 || pile->size_a == 1 || (pile->size_b == 0
			|| pile->size_b == 1))
		return ;
	i = pile->size_a - 1;
	tmp = pile->pile_a[i];
	while (i)
	{
		pile->pile_a[i] = pile->pile_a[i - 1];
		i--;
	}
	pile->pile_a[i] = tmp;
	i = pile->size_b - 1;
	tmp = pile->pile_b[i];
	while (i--)
		pile->pile_b[i] = pile->pile_b[i - 1];
	pile->pile_b[i] = tmp;
	ft_printf("rrr\n");
}
