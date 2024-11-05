/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:52:33 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 15:19:52 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*tdest;
	const char	*tsrc;
	size_t		i;

	tdest = dest;
	tsrc = src;
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (*tsrc && i < (size - 1))
	{
		*tdest++ = *tsrc++;
		i++;
	}
	*tdest = '\0';
	while (*tsrc++)
		i++;
	return (i);
}
