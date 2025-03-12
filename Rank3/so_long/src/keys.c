/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:19:43 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/28 12:55:09 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void 	ft_move(so_long_t *game_info, int x, int y)
{
	game_info->player_x = x;
	game_info->player_y = y;
	game_info->step_count++;
	if(game_info->map[x][y] == COLLECTIBLE)
	{
		game_info->collectible_count--;
		game_info->map[x][y] = SPACE;
	}
	if( game_info->collectible_count == 0 && game_info->map[x][y] == EXIT)
	{
		exit(EXIT_SUCCESS);
	}
	printf("Steps taken to victory: %d", game_info->step_count);
}

int 	ft_key_hooks(int keycode, so_long_t *game_info)
{	
	if (keycode == 65307)
		ft_quit(game_info);
	if (keycode == 65362 || keycode == 119)
	{
		if (game_info->playable[game_info->player_x - 1][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x - 1, game_info->player_y);
	}
	if (keycode == 65363 || keycode == 100)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y + 1] != '1')
			ft_move(game_info, game_info->player_x, game_info->player_y + 1);
	}
	if (keycode == 65364 || keycode == 115)
	{
		if (game_info->playable[game_info->player_x + 1][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x + 1, game_info->player_y);
	}
	if (keycode == 65361 || keycode == 97)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y - 1] != '1')
			ft_move(game_info, game_info->player_x, game_info->player_y - 1);
	}
	return (0);
}