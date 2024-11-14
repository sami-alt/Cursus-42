/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 09:43:29 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/12 09:33:36 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{	
	if (nb < 0)
		return (0);
	if (nb >= 1)
		return (nb * ft_recursive_factorial(nb - 1));
	return (1);
}
