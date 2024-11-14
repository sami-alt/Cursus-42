/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:25:47 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/08 11:49:31 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{	
	int	temp;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}
/*
int main(){
	int num[5] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(num, 5);
	int i;	
	while(i < 5){
		printf("%d",num[i]);
		i++;
	}
}*/