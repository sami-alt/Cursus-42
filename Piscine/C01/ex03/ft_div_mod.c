/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 10:39:32 by sraiha            #+#    #+#             */
/*   Updated: 2024/09/07 17:12:22 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(){
	int a =  5;
	int b = 2;
	int div;
	int mod;
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d", div ,mod);
}*/