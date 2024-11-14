/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:11:01 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/09 12:41:54 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*temp;

	temp = str;
	while (*temp)
	{
		if (*temp >= 'a' && *temp <= 'z')
		{
			*temp = *temp - (char)32;
		}
		temp++;
	}
	return (str);
}
