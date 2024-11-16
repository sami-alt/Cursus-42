/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:56:32 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/17 11:41:08 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		temp++;
	}
	return (temp - str);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	char	*test;

	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	test = dest;
	if (!test)
		return (0);
	while (*src)
	{
		*test++ = *src++;
	}
	*test = '\0';
	return (dest);
}
