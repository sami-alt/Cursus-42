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

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct piles_s
{
    int *pile_a;
    int *pile_b;
    int size_a;
    int size_b;    
} piles_t;

//push.c
void    push_a(piles_t *pile);
void    push_b(piles_t *pile);

//swap.c
void	swap_a(piles_t *pile);
void	swap_b(piles_t *pile);
void	swap_s(piles_t *pile);

//rotate.c
void    rotate_a(piles_t *pile);
void    rotate_b(piles_t *pile);
void    rotate_r(piles_t *pile);

//revese_sort.c
void	swap_s(piles_t *pile);
void	reverse_rotate_a(piles_t *pile);
void	reverse_rotate_b(piles_t *pile);

//utils.c
void 	error(int *pile);
int 	push_swap_atoi(char *str, int *pile);
int 	push_swap_strlen(char **av);
int 	check_sorted(int *pile, int size, int order);
void 	check_for_doubles(int *pile, int size);

//quicksort.c
void	sort_three_a_b(piles_t *pile, int len);
int 	sort_three_b(piles_t *pile, int len);
int 	find_pivot(int *pivot, int *pile, int size);
int		quicksort_pile_a(piles_t *pile, int len, int count);
int 	quicksort_pile_b(piles_t *pile, int len, int count);

//sort.c
void	temp_sort(int *temp_pile, int size);
void	sort_three_a(piles_t *pile);
int		sort(piles_t *pile, int size);
int		ft_push(piles_t *pile, int len, int push);

//push_swap.c
void    push_swap(char **av);
int 	push_swap_strlen(char **av);

#endif