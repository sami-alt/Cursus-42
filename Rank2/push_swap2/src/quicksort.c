/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:39:31 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 17:12:34 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_a_b(piles_t *pile, int len)
{
	if(len == 3 && pile->size_a == 3)
		sort_three_a(pile);
	else if(len == 2)
	{
		if (pile->pile_a[0] > pile->pile_a[1])
			swap_a(pile);
	}
	else if (len == 3 )
	{
		while (len != 3 || !(pile->pile_a[0] < pile->pile_a[1]
			&& pile->pile_a[1] < pile->pile_a[2]))
	{
		if (len == 3 && pile->pile_a[0] > pile->pile_a[1] && pile->pile_a[2])
			swap_a(pile);
		else if (len == 3 && !(pile->pile_a[2] > pile->pile_a[0]
				&& pile->pile_a[2] > pile->pile_a[1]))
			len = ft_push(pile, len, 0);
		else if (pile->pile_a[0] > pile->pile_a[1])
			swap_a(pile);
		else if (len++)
			push_a(pile);
	}
	}
}


int	sort_three_b(piles_t *pile, int len)
{
	if (len == 1)
		push_a(pile);
	else if (len == 2)
	{
		if (pile->pile_b[0] < pile->pile_b[1])
			swap_b(pile);
		while (len--)
			push_a(pile);
	}
	else if (len == 3)
	{
		while (len || !(pile->pile_a[0] < pile->pile_a[1] && pile->pile_a[1] < pile->pile_a[2]))
		{
			if (len == 1 && pile->pile_a[0] > pile->pile_a[1])
				swap_a(pile);
			else if (len == 1 || (len >= 2 && pile->pile_b[0] > pile->pile_b[1])
				|| (len == 3 && pile->pile_b[0] > pile->pile_b[2]))
				len = ft_push(pile, len, 1);
			else
				swap_b(pile);
		}
	}
	return (0);
}

int 	find_pivot(int *pivot, int *pile, int size)
{
	int		*temp_pile;
	int 	i;

	temp_pile = malloc(size * sizeof(int));
	if(!temp_pile)
		return (0);
	i = 0;
	while(i < size)
	{
		temp_pile[i] = pile[i];
		i++;
	}
	temp_sort(temp_pile, size);
	*pivot = temp_pile[size / 2];
	free(temp_pile);
	return (1);
}

int	quicksort_pile_a(piles_t *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_sorted(pile->pile_a, len, 0) == 1)
		return (1);
	numbers = len;
	if (len <= 3)
	{
		sort_three_a_b(pile, len);
		return (1);
	}
	
	if (!find_pivot(&pivot, pile->pile_a, len))
		return (0);
	while (len != numbers / 2 + numbers % 2)
	{
		if (pile->pile_a[0] < pivot && (len--))
			push_b(pile);
		else if (++count_r)
			rotate_a(pile);
	}
	while (numbers / 2 + numbers % 2 != pile->size_a && count_r--)
		reverse_rotate_a(pile);
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
	return (1);
}


int	quicksort_pile_b(piles_t *pile, int len, int count_r)
{
	int	pivot;
	int	numbers;


	if (check_sorted(pile->pile_b, len, 1) == 1)
		while (len--)
			push_a(pile);
	if (len <= 3)
	{
		sort_three_b(pile, len);
		return (1);
	}
	numbers = len;
	if (!find_pivot(&pivot, pile->pile_b, len))
		return (0);
	while (len != numbers / 2)
	{
		if (pile->pile_b[0] >= pivot && len--)
			push_a(pile);
		else if (++count_r)
			rotate_b(pile);
	}
	while (numbers / 2 != pile->size_b && count_r--)
		reverse_rotate_b(pile);
	return (quicksort_pile_a(pile, numbers / 2 + numbers % 2, 0)
		&& quicksort_pile_b(pile, numbers / 2, 0));
}