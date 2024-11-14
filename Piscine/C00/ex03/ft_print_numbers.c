/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:14:28 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/08 15:55:25 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	num;

	num = 48;
	while (num <= 57)
	{
		write(1, &num, 1);
		num++;
	}
}
/*
int main(){
	ft_print_numbers();
}*/
