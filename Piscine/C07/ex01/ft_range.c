/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 14:03:20 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/17 11:38:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		range;
	int		i;
	int		*result;

	if (max <= min)
		return (0);
	range = max - min;
	result = (int *)malloc(range * sizeof(result));
	if (!result)
		return (0);
	i = 0;
	while (i < range)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
