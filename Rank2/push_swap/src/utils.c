/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:38:47 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/28 14:30:33 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(t_piles *pile, char **av, int alloc)
{
	free(pile->pile_a);
	free(pile->pile_b);
	if (alloc)
		free_av(av);
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

int	push_swap_strlen(char **av)
{
	int	i;

	i = 0;
	while (*av)
	{
		av++;
		i++;
	}
	return (i);
}

int	push_swap_atoi(char *str, t_piles *pile, char **av, int alloc)
{
	unsigned int		i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit(str[i + 1]))
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(pile, av, alloc);
		number = (str[i] - '0') + (number * 10);
		i++;
	}
	if ((number > 2147483648 && sign == -1) || (number > 2147483647
			&& sign == 1))
		error(pile, av, alloc);
	return (number * sign);
}

int	check_sorted(int *pile, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (pile[i - 1] > pile[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (pile[i - 1] < pile[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	check_for_doubles(t_piles *pile, int size, char **av, int alloc)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (pile->pile_a[i] == pile->pile_a[j])
				error(pile, av, alloc);
			j++;
		}
		i++;
		j = i + 1;
	}
}
