/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:33 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/07 14:37:20 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*res;
	char	*start;
	char	*end;

	if (!*s1)
		return (ft_strdup(""));
	start = (char *)s1;
	end = ft_strlen(s1) + start;
	while (*start && ft_inset(*start, set))
		start++;
	while (start < end && ft_inset(*(end - 1), set))
		end--;
	res = ft_substr(start, 0, end - start);
	return (res);
}

#include <stdio.h>
int main()
{
	char test[] = "Hello world!";
	char *res;

	res = ft_strtrim(test, "");

	printf("%s", res);
}