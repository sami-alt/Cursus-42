/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:35:41 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/16 11:57:29 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{	
	char	*temp;

	temp = dest;
	while (*temp)
	{
		temp++;
	}
	while (*src && nb > 0)
	{
		*temp++ = *src++;
		nb--;
	}
	*temp = '\0';
	return (dest);
}
