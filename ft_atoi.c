/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:06:06 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/04 14:43:55 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int	ft_is_operator(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

signed long long	ft_atoi(char *str)
{
	long long		out;
	int				sign;

	out = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (ft_is_operator(*str))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_is_number(*str))
	{
		out = out * 10 + (*str++ - '0');
		if (out > LLONG_MAX)
			return (-1);
		else if (out < LLONG_MIN)
			return (0);
	}
	return (out * sign);
}
