/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:13:46 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 13:56:55 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;
	size_t			len;

	len = ft_strlen(s);
	if (!s)
		return (NULL);
	res = (char *)malloc(ft_strlen(s) + 1);
	i = 1;
	while (*s)
	{
		*res++ = (*f)(i, *s++);
	}
	*res = '\0';
	return (res - len);
}
