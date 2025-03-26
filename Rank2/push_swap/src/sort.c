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


#include "../include/push_swap.h"

void	temp_sort(int *temp_pile, int size)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while(i < size)
	{
		j = i + 1;
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

void	sort_three_a(piles_t *three)
{
	if (three->pile_a[0] > three->pile_a[1] && three->pile_a[0] < three->pile_a[2]
		&& three->pile_a[1] < three->pile_a[2])
		swap_a(three);
	if (three->pile_a[0] > three->pile_a[1] && three->pile_a[0] > three->pile_a[2]
		&& three->pile_a[1] > three->pile_a[2])
	{
		swap_a(three);
		reverse_rotate_a(three);
	}
	if (three->pile_a[0] > three->pile_a[1] && three->pile_a[0] > three->pile_a[2]
		&& three->pile_a[1] < three->pile_a[2])
		rotate_a(three);
	if (three->pile_a[0] < three->pile_a[1] && three->pile_a[0] < three->pile_a[2]
		&& three->pile_a[1] > three->pile_a[2])
	{
		swap_a(three);
		rotate_a(three);
	}
	if (three->pile_a[0] < three->pile_a[1] && three->pile_a[0] > three->pile_a[2]
		&& three->pile_a[1] > three->pile_a[2])
		reverse_rotate_a(three);
}

int		sort(piles_t *pile, int size)
{
	if(check_sorted(pile->pile_a, pile->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(pile);
		else if (size == 3)
			sort_three_a(pile);
		else
			quicksort_pile_a(pile, size, 0);
	}
	return (0);
}

int		ft_push(piles_t *pile, int len, int push)
{
	if (push == 0)
		push_b(pile);
	else
		push_a(pile);
	len--;
	return (len);
}