/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:38:47 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 14:38:14 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	error(int *pile)
{
	free(pile);
	ft_printf("Error\n");
	exit(1);
}

int 	push_swap_strlen(char **av)
{
	int		i;
	
	i = 0;
	while(*av)
	{
		av++;
		i++;
	}
	return (i);
}

int 	push_swap_atoi(char *str, int *pile)
{
	unsigned int	i;
	int					sign;
	unsigned long int	number;

	i = 0;
	number = 0;
	sign  = 1;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while(str[i] == '-' || str[i] == '+')
		if (str[i] == '-')
			sign = -1;
		i++;
	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			error(pile);
		number = number * 10 + (str[i]  - '0');
		i++;	
	}
	if((number > 2147483648 && sign == -1) || (number > 2147483648 && sign == 1))
		error(pile);
	return (number  * sign);
}
int 	check_sorted(int *pile, int size, int order)
{
	int 	i;

	if (order == 0)
	{
		i = 1;
		while(i < size)
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
		while(i < size)
		{
			if (pile[i - 1] < pile[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void 	check_for_doubles(int *pile, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(i < size)
	{
		while(j < size)
		{
			if(pile[i] == pile[j])
				error(pile);
			j++;
		}
		i++;
		j = i + 1;
	}

}
