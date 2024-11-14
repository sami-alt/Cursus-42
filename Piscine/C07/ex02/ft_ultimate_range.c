/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:22:00 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/17 11:37:11 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{	
	int		size;
	int		i;
	int		*arr;

	if (max <= min)
	{	
		*range = 0;
		return (0);
	}
	size = max - min - 1;
	arr = (int *)malloc(size * sizeof(arr));
	if (!arr)
	{
		*arr = 0;
		return (-1);
	}
	i = 0;
	while (i <= size)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (size + 1);
}
