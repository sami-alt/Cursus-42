/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num_by_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:20:26 by sraiha            #+#    #+#             */
/*   Updated: 2024/12/11 15:18:45 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_num_len(unsigned long nb, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (nb >= base_len)
	{
		nb /= base_len;
		len++;
	}
	return (len);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}

char	*ft_put_num_by_base(unsigned long long num, char *base)
{	
	char		*number;
	size_t		num_len;
	size_t		base_size;

	num_len = ft_num_len(num, base);
	base_size = ft_strlen(base);
	number = ft_calloc((num_len + 1), sizeof(char));
	while (num_len)
	{
		num_len--;
		number[num_len] = base[num % base_size];
		num /= base_size;
	}	
	return (number);
}
