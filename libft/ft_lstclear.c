/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:55:03 by sraiha            #+#    #+#             */
/*   Updated: 2024/11/05 14:06:22 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*del_from;

	del_from = *lst;
	while (del_from)
	{
		next = del_from->next;
		del(del_from->content);
		free(del_from);
		del_from = next;
	}
	free(lst);
	*lst = NULL;
}
