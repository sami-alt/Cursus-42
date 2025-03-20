/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:19:43 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 17:01:07 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_move(t_so_long *game, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	game->step_count++;
	ft_draw_background(game);
	ft_draw_playable(game);
	if (game->map[x][y] == COLLECTIBLE)
	{	
		game->collectible_count--;
		game->map[x][y] = SPACE;
	}
	ft_printf("Steps takes: %d\n", game->step_count);
	if (game->collectible_count == 0 && game->map[x][y] == EXIT)
	{	
		ft_quit(game);
		exit(EXIT_SUCCESS);
	}
}

int	ft_key_hooks(int keycode, t_so_long *game)
{
	if (keycode == 65307)
		ft_quit(game);
	if (keycode == 65362 || keycode == 119)
	{
		if (game->playable[game->player_x - 1][game->player_y] != '1')
			ft_move(game, game->player_x - 1, game->player_y);
	}
	if (keycode == 65363 || keycode == 100)
	{
		if (game->playable[game->player_x][game->player_y + 1] != '1')
			ft_move(game, game->player_x, game->player_y + 1);
	}
	if (keycode == 65364 || keycode == 115)
	{
		if (game->playable[game->player_x + 1][game->player_y] != '1')
			ft_move(game, game->player_x + 1, game->player_y);
	}
	if (keycode == 65361 || keycode == 97)
	{
		if (game->playable[game->player_x][game->player_y - 1] != '1')
			ft_move(game, game->player_x, game->player_y - 1);
	}
	return (0);
}
