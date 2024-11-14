/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:29:45 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 13:19:15 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	found;

	found = (char)c;
	while (*s)
	{
		if (*s == found)
			return ((char *)s);
		s++;
	}
	if (*s == found)
		return ((char *)s);
	return (NULL);
}
