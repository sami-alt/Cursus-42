/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 09:56:55 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/08 16:13:33 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	nums(int i, int j)
{
	char	a1;
	char	a2;
	char	b1;
	char	b2;

	a1 = '0' + i / 10;
	write(1, &a1, 1);
	a2 = '0' + i % 10;
	write(1, &a2, 1);
	write(1, " ", 1);
	b1 = '0' + j / 10;
	write(1, &b1, 1);
	b2 = '0' + j % 10;
	write(1, &b2, 1);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			nums(i, j);
			if (i != 98 || j != 99)
			{
				write(1, ", ", 2);
			}
			j++;
		}
		i++;
	}
}
/*
int main(){
	ft_print_comb2();
}*/
