/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 4040/02/23 11:38:21 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 16:03:11 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_draw_player(t_so_long *game_info)
{
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win,
		game_info->player, game_info->player_y * 40, game_info->player_x * 40);
	return (0);
}

int	ft_draw_playable(t_so_long *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j] != '\0')
		{
			if (game_info->map[i][j] == 'E')
				mlx_put_image_to_window(game_info->mlx, game_info->mlx_win,
					game_info->exit, j * 40, i * 40);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_draw_background(t_so_long *game_info)
{
	int	i;
	int	j;

	i = 0;
	while (game_info->map[i])
	{
		j = 0;
		while (game_info->map[i][j] != '\0')
		{
			if (game_info->map[i][j] == '1')
				mlx_put_image_to_window(game_info->mlx, game_info->mlx_win,
					game_info->wall, j * 40, i * 40);
			else if (game_info->map[i][j] == '0' || (game_info->map[i][j] == 'P'
					&& (game_info->player_x != i || game_info->player_y != j)))
				mlx_put_image_to_window(game_info->mlx, game_info->mlx_win,
					game_info->floor, j * 40, i * 40);
			else if (game_info->map[i][j] == 'C')
				mlx_put_image_to_window(game_info->mlx, game_info->mlx_win,
					game_info->collectible, j * 40, i * 40);
			j++;
		}
		i++;
	}
}
