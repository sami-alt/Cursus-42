/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:42:59 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/23 16:09:04 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int		i;
	char	*count;

	count = str;
	i = 0;
	while (*count++)
	{
		i++;
	}
	return (i);
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

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < ac)
	{
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		tab[i].size = ft_strlen(av[i]);
		i++;
	}
	tab[i].str = 0;
	tab[i].copy = 0;
	return (tab);
}
