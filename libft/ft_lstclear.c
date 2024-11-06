/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:55:03 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/06 15:46:02 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*next;
	t_list		*del_from;

	if (lst)
	{
		del_from = *lst;
		while (del_from)
		{	
			next = del_from->next;
			ft_lstdelone(del_from, (del));
			del_from = next;
		}
	}
	*lst = NULL;
}
