/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:45:25 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/11 14:44:12 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{	
	char	*search;
	char	*find;

	search = str;
	find = to_find;
	if (*to_find == '\0')
	{
		return (str);
	}
	while (1)
	{	
		if (*find == '\0')
			return (search - (find - to_find));
		if (*search == *find)
			find++;
		else
			find = to_find;
		if (*search == '\0')
			return (0);
		search++;
	}
	return (0);
}
