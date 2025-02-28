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

int 	ft_key_hooks(int key_code, so_long_t *game_info)
{
	if (key_code == 53)
		ft_quit(game_info);
	if (key_code == 13 || key_code == 126)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x - 1, game_info->player_y);
	}
	if (key_code == 2 || key_code == 124)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x, game_info->player_y + 1);
	}
	if (key_code == 1 || key_code == 125)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x + 1, game_info->player_y);
	}
	if (key_code == 0   || key_code == 123)
	{
		if (game_info->playable[game_info->player_x][game_info->player_y] != '1')
			ft_move(game_info, game_info->player_x, game_info->player_y - 1);
	}
	return (0);
}