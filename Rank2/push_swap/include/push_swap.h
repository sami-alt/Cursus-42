/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:38:31 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/28 14:23:26 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include <stdlib.h>

typedef struct piles_s
{
	int	*pile_a;
	int	*pile_b;
	int	size_a;
	int	size_b;
}		t_piles;

void	push_a(t_piles *pile);
void	push_b(t_piles *pile);
void	swap_a(t_piles *pile);
void	swap_b(t_piles *pile);
void	swap_s(t_piles *pile);
void	rotate_a(t_piles *pile);
void	rotate_b(t_piles *pile);
void	rotate_r(t_piles *pile);
void	swap_s(t_piles *pile);
void	reverse_rotate_a(t_piles *pile);
void	reverse_rotate_b(t_piles *pile);
int		push_swap_strlen(char **av);
int		check_sorted(int *pile, int size, int order);
void	sort_three_a_b(t_piles *pile, int len);
int		sort_three_b(t_piles *pile, int len);
int		find_pivot(int *pivot, int *pile, int size);
int		quicksort_pile_a(t_piles *pile, int len, int count);
int		quicksort_pile_b(t_piles *pile, int len, int count);
void	temp_sort(int *temp_pile, int size);
void	sort_three_a(t_piles *pile);
int		sort(t_piles *pile, int size);
int		ft_push(t_piles *pile, int len, int push);
void	push_swap(char **av, int alloc);
int		push_swap_strlen(char **av);

void	check_for_doubles(t_piles *pile, int size, char **av, int alloc);
int		push_swap_atoi(char *str, t_piles *pile, char **av, int alloc);
void	error(t_piles *pile, char **av, int alloc);
void	free_av(char **av);

#endif