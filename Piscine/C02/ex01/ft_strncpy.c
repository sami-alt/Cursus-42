/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:19:15 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/15 13:59:11 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	char			*temp;

	i = 0;
	temp = dest;
	while (*src && i < n)
	{
		*temp++ = *src++;
		i++;
	}
	while (i < n)
	{
		*temp = '\0';
		temp++;
		i++;
	}
	return (dest);
}

#include <stdio.h>
int main()
{
	char str1[] = "test";
	char str2[3] = "";
		
	printf("%s", ft_strncpy(str2, str1, 3));

}
