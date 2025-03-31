/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:47:34 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/28 14:44:17 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

void	push_swap(char **av, int alloc)
{
	t_piles	pile;
	int		size;
	int		i;

	i = -1;
	size = push_swap_strlen(av);
	pile.pile_a = malloc(size * sizeof(int));
	if (!pile.pile_a)
		return ;
	pile.size_a = size;
	pile.pile_b = malloc(size * sizeof(int));
	if (!pile.pile_b)
	{
		free(pile.pile_a);
		return ;
	}
	pile.size_b = 0;
	while (++i < size)
		pile.pile_a[i] = push_swap_atoi(av[i], &pile, av, alloc);
	check_for_doubles(&pile, size, av, alloc);
	sort(&pile, size);
	if (alloc)
		free_av(av);
	free(pile.pile_a);
	free(pile.pile_b);
}

int	main(int ac, char **av)
{
	char	**input;
	int		alloc;

	alloc = 0;
	av++;
	input = av;
	if (ac > 1)
	{
		if (*av[0] == '\0')
			write(2, "Error\n", 6);
		if (ac == 2)
		{
			alloc = 1;
			input = ft_split(*av, ' ');
		}
		push_swap(input, alloc);
		return (0);
	}
	return (0);
}
