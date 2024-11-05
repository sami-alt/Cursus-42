/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:08:50 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 15:40:27 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
		}
		else
		{
			s++;
		}
	}
	return (len);
}

char	**ft_split(const char *s, char c)
{
	char		**res;
	size_t		len;
	int			i;

	i = 0;
	if (!s)
		return (0);
	res = malloc(sizeof(char *) * ft_len(s, c) + 1);
	if (!res)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				s++;
			res[i] = ft_substr(s - len, 0, len);
			i++;
		}
		else
			++s;
	}
	res[i + 1] = NULL;
	return (res - i);
}
