/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:59:47 by sraiha            #+#    #+#             */
/*   Updated: 2025/03/19 16:28:08 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_is_winnable(t_so_long *gi)
{
	gi->modified = 0;
	gi->row = 0;
	while (gi->map[gi->row] != NULL)
	{
		gi->column = 0;
		while (gi->playable[gi->row][gi->column] != '\0')
		{
			if (gi->playable[gi->row][gi->column] == COLLECTIBLE
				|| gi->playable[gi->row][gi->column] == EXIT)
				return (write(1, "Error\nNot winnable\n", 19), 1);
			gi->column++;
		}
		gi->row++;
	}
	return (0);
}

void	mark_playable(t_so_long *game_info)
{
	if (game_info->playable[game_info->row - 1][game_info->column] != WALL
		&& game_info->playable[game_info->row - 1][game_info->column] != 'O')
	{
		game_info->modified = 1;
		game_info->playable[game_info->row - 1][game_info->column] = 'O';
	}
	if (game_info->playable[game_info->row + 1][game_info->column] != WALL
		&& game_info->playable[game_info->row + 1][game_info->column] != 'O')
	{
		game_info->modified = 1;
		game_info->playable[game_info->row + 1][game_info->column] = 'O';
	}
	if (game_info->playable[game_info->row][game_info->column - 1] != WALL
		&& game_info->playable[game_info->row][game_info->column - 1] != 'O')
	{
		game_info->modified = 1;
		game_info->playable[game_info->row][game_info->column - 1] = 'O';
	}
	if (game_info->playable[game_info->row][game_info->column + 1] != WALL
		&& game_info->playable[game_info->row][game_info->column + 1] != 'O')
	{
		game_info->modified = 1;
		game_info->playable[game_info->row][game_info->column + 1] = 'O';
	}
}

int	find_playable(t_so_long *game_info)
{
	game_info->modified = 0;
	game_info->row = 0;
	while (game_info->playable[game_info->row] != NULL)
	{
		game_info->column = 0;
		while (game_info->playable[game_info->row][game_info->column] != '\0')
		{
			if (game_info->playable[game_info->row][game_info->column] == 'O')
				mark_playable(game_info);
			game_info->column++;
		}
		game_info->row++;
	}
	return (0);
}

int	ft_player_location(t_so_long *game)
{
	game->row = 0;
	while (game->playable[game->row] != NULL)
	{
		game->column = 0;
		while (game->playable[game->row][game->column] != 0)
		{
			if (game->playable[game->row][game->column] == PLAYER)
			{
				game->player_x = game->row;
				game->player_y = game->column;
				game->playable[game->row][game->column] = 'O';
			}
			game->column++;
		}
		game->row++;
	}
	game->modified = 1;
	while (game->modified == 1)
		find_playable(game);
	if (ft_is_winnable(game) != 0)
		return (1);
	return (0);
}

int	ft_error(t_so_long *game_info)
{
	if (ft_check_map_chars(game_info->map_raw) == 1)
		return (1);
	if (ft_validate_player_collectibles_exit(game_info) == 1)
		return (1);
	if (ft_check_shape(game_info) == 1)
		return (1);
	if (ft_wall_check(game_info) == 1)
		return (1);
	if (ft_player_location(game_info) == 1)
		return (1);
	return (0);
}
