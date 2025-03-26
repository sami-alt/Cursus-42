/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:36:22 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/25 14:59:56 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1)
		return ;
	i = 0;
	tmp = pile->pile_a[i];
	i++;
	while (i < pile->size_a)
	{
		pile->pile_a[i - 1] = pile->pile_a[i];
		i++;
	}
	pile->pile_a[i - 1] = tmp;
	ft_printf("ra\n");
}

void	rotate_b(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_b == 0 || pile->size_b == 1)
		return ;
	i = 0;
	tmp = pile->pile_b[i];
	i++;
	while (i < pile->size_b)
	{
		pile->pile_b[i - 1] = pile->pile_b[i];
		i++;
	}
	pile->pile_b[i - 1] = tmp;
	ft_printf("rb\n");
}

void	rotate_r(t_piles *pile)
{
	int	tmp;
	int	i;

	if (pile->size_a == 0 || pile->size_a == 1 || (pile->size_b == 0
			|| pile->size_b == 1))
		return ;
	i = 0;
	tmp = pile->pile_a[i];
	while (++i < pile->size_a)
		pile->pile_a[i - 1] = pile->pile_a[i];
	pile->pile_a[i - 1] = tmp;
	i = 0;
	tmp = pile->pile_b[i];
	while (++i < pile->size_b)
		pile->pile_b[i - 1] = pile->pile_b[i];
	pile->pile_b[i - 1] = tmp;
	ft_printf("rr\n");
}
