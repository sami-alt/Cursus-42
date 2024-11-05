/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:29:18 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 15:59:02 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	const char	*temp;
	char		*ret;

	ret = (char *)dest;
	temp = (char *)src;
	i = 0;
	if (!dest || !src)
		return (NULL);
	while (n--)
	{
		*ret++ = *temp++;
		i++;
	}
	return (dest);
}
