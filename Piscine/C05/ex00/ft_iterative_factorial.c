/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:11:24 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/12 09:20:58 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{	
	int	i;
	int	factorial;

	if (nb < 0)
		return (0);
	factorial = 1;
	i = 1;
	while (i <= nb)
	{
		factorial = factorial * i;
		i++;
	}
	return (factorial);
}
