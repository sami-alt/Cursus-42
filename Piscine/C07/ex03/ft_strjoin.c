/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:42:21 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/19 09:54:25 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	temp = str;
	while (*temp)
	{
		temp++;
		i++;
	}
	return (i);
}

int	ft_full_len(int size, char **strs, int sep)
{
	int	full_lenght;
	int	i;

	full_lenght = 0;
	i = 0;
	while (i < size)
	{
		full_lenght += ft_strlen(strs[i]) + sep;
		i++;
	}
	full_lenght -= sep;
	return (full_lenght);
}	

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*result;
	char	*add;
	int		len;

	if (size == 0)
		result = (char *)malloc(1);
	len = ft_full_len(size, strs, ft_strlen(sep));
	result = (char *)malloc((len + 1) * sizeof(char));
	add = result;
	if (!add)
		return (0);
	len = 0;
	while (len < size)
	{
		ft_strcpy(add, strs[len]);
		add += ft_strlen(strs[len]);
		if (len < size - 1)
		{
			ft_strcpy(add, sep);
			add += ft_strlen(sep);
		}
		len++;
	}
	*add = '\0';
	return (result);
}
