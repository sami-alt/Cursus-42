/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:30:37 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/08 11:48:57 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (size >= 0)
	{
		i = 0;
		while (i < size - 1)
		{	
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				i = 0;
			}
			i++;
		}
		size--;
	}
}
/*
int main(){
	int nums[5] = {3, 4, 5, 2, 1};
	int i = 0;
	ft_sort_int_tab(nums, 5);
	while(i < 5){
		printf("%d", nums[i]);
		i++;
	}
}*/