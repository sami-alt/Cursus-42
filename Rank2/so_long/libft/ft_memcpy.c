/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:29:18 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/15 12:33:28 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*temp;
	char		*ret;

	ret = (char *)dest;
	temp = (char *)src;
	while (n--)
	{
		*ret++ = *temp++;
	}
	return (dest);
}
