/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 11:40:34 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/09 13:15:33 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{		
		write(1, str, 1);
		str++;
	}	
}
/*
int main(){
	ft_putstr("text from here");
	write(1, "\n", 1);
	ft_putstr("and here");
}*/
