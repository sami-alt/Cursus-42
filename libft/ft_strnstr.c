/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:05:16 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 10:49:21 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	const char	*temp_haystack;
	const char	*temp_needle;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen(needle) > len || !*haystack)
		return (NULL);
	while (i++ < len && *haystack)
	{
		temp_haystack = haystack;
		temp_needle = needle;
		while (*temp_needle && *temp_haystack == *temp_needle && i < len)
		{
			temp_haystack++;
			temp_needle++;
			i++;
		}
		if (!*temp_needle)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
