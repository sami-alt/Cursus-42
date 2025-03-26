/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:50:38 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/23 11:46:14 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *counter)
{	
	if (*counter == -1)
		return ;
	if (write(1, &c, 1) == -1)
		*counter = -1;
	else
		*counter += 1;
}
