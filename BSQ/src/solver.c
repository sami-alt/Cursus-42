
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jforsten <jforsten@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:47:40 by jforsten          #+#    #+#             */
/*   Updated: 2024/09/25 21:16:51 by jforsten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<bsq.h>
#include<stdio.h>

void	separator(t_map *file_info, t_solution *solution_info, int row, int col, int size)
{
	(void)file_info;
	if (size > solution_info->size)
	{
		solution_info->size = size;
		solution_info->y = row;
		solution_info->x = col;
		printf("Size..%d\n", size);
	}
}

void	expander(t_map *file_info, t_solution *solution_info, int row, int col)
{
	int	y;
	int	x;
	int z;

	if ((file_info->cols - col) <= (file_info->rows - row))
		z = (file_info->cols - col) - 1;
	else
		z = (file_info->rows - row) - 1;
	//printf("Z..%d\n", z);
	y = row;
	while (y < z)
	{
		x  = col;
		while (x < z)
		{
			if (file_info->map[y][x] == file_info->obstacle_char)
			{
				z--;
				x = col;
				y = row - 1;
				printf("Z..%d\n", z);
				break ;
			}
			x++;
		}
		y++;
	}
	separator(file_info, solution_info, row, col, z);
}

void	solver(t_map *file_info, t_solution *solution_info)
{
	int	c;
	int	y;
	int	x;

	c = file_info->cols;
	y = 0;
	while (y < c)
	{
		x = 0;
		while (x < c)
		{
			if (file_info->map[y][x] != file_info->obstacle_char)
			{
				//printf("%c\n", file_info->map[y][x]);
				expander(file_info, solution_info, y, x);
			}
			x++;
		}
		y++;
	}
	//printf("y:%d x:%d\n", y , x);
}
