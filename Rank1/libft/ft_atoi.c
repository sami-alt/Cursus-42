/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:06 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/14 11:13:46 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space( char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	long long		flow_check;
	long long		res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		flow_check = res * 10 + (*str++ - '0');
		if (flow_check / 10 != res && sign < 0)
			return (0);
		else if (flow_check / 10 != res && sign > 0)
			return (-1);
		res = flow_check;
	}
	return ((int)res * sign);
}
