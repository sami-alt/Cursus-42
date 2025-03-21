/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-13 11:47:34 by sraiha            #+#    #+#             */
/*   Updated: 2025-01-13 11:47:34 by sraiha           ###   ########.fi       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	temp_sort(int *temp_pile, int size)
{
	int		i;
	int		j;
	int		temp;

	while(i < size)
	{
		i = j + 1;
		while(j < size)
		{
			if (temp_pile[i] > temp_pile[j])
			{
				temp = temp_pile[i];
				temp_pile[i] = temp_pile[j];
				temp_pile[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	sort_three_a(pile_t *pile)
{
	if(pile->pile_a[0] > pile->pile_a[1] && pile->pile_a[0] < pile->pile_a[2] && pile->pile_a[1] < pile->pile_a[2] )
		swap_a(pile);
	if(pile->pile_a[0] > pile->pile_a[1] && pile->pile_a[0] > pile->pile_a[2] && pile->pile_a[1] > pile->pile_a[2] )
	{
		swap_a(pile);
		reverse_rotate_a(pile);
	}
	if(pile->pile_a[0] > pile->pile_a[1] && pile->pile_a[0] > pile->pile_a[2] && pile->pile_a[1] < pile->pile_a[2] )
		rotate_a(pile);
	if(pile->pile_a[0] < pile->pile_a[1] && pile->pile_a[0] < pile->pile_a[2] && pile->pile_a[1] > pile->pile_a[2] )
	{
		swap_a(pile);
		rotate_a(pile);
	}
	if(pile->pile_a[0] < pile->pile_a[1] && pile->pile_a[0] > pile->pile_a[2] && pile->pile_a[1] > pile->pile_a[2] )
		reverse_rotate_a(pile);
}

int		sort(piles_t pile, int size)
{
	if(check_sorted(pile->pile_a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile);
		else if (size == 3)
			sort_three_a(pile);
		else
			quicksort_a(pile, size, 0);
	}
	return (0);
}

int		ft_push(piles_t *pile, int len, int push)
{
	if (push == 0)
		push_b(pile);
	else
		push_a(pile);
	len--
return (len);
}