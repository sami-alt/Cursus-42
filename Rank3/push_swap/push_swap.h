/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:38:31 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/20 13:42:21 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>

typedef struct piles_s
{
    int *pile_a;
    int *pile_b;
    int size_a;
    int size_b;    
} piles_t;

void	temp_sort(int *temp_pile, int size);
int 	push_swap_atoi(char *str, int *pile);
int 	push_swap_strlen(char **av);
int 	check_sorted(int *pile, int size, int order);
void 	check_for_doubles(int *pile, int size);
int		sort(piles_t pile, int size);

#endif