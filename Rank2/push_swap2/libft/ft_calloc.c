/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 15:48:37 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/11 09:46:33 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			mem_size;

	mem_size = count * size;
	if (count != 0 && mem_size / count != size)
		return (NULL);
	if (mem_size == 0)
		return (malloc(0));
	mem = malloc(mem_size);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, mem_size);
	return (mem);
}
