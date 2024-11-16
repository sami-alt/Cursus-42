/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:43:41 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/12 09:35:16 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{	
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	while (power-- > 0)
	{
		res = res * nb;
	}
	return (res);
}
