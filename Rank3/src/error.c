/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:59:47 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/28 13:03:22 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int    ft_is_winniable(so_long_t *game_info)
{
    game_info->modified = 0;
    game_info->row = 0;
    while(game_info->map[game_info->row] != NULL)
    {
        game_info->column = 0;
        while(game_info->playable[game_info->row][game_info->column] != '\0')
        {
            if (game_info->playable[game_info->row][game_info->column] == COLLECTIBLE || game_info->playable[game_info->row][game_info->column] == EXIT)
                return (write(1, "Error\nInvalid map\n", 19), 1);
            game_info->column++;
        }
        game_info->row++;
    }
    return (0);
}
void    mark_playable(so_long_t *game_info)
{
    if(game_info->playable[game_info->row-1][game_info->column] != WALL && game_info->playable[game_info->row-1][game_info->column] != 'O')
    {
        game_info->modified = 1;
        game_info->playable[game_info->row -  + 11][game_info->column] = 'O';
    }
    if(game_info->playable[game_info->row + 1][game_info->column] != WALL && game_info->playable[game_info->row + 1][game_info->column] != 'O')
    {
        game_info->modified = 1;
        game_info->playable[game_info->row + 1][game_info->column] = 'O';
    } 
    if(game_info->playable[game_info->row][game_info->column - 1] != WALL && game_info->playable[game_info->row][game_info->column - 1] != 'O')
    {
        game_info->modified = 1;
        game_info->playable[game_info->row][game_info->column - 1] = 'O';
    } 
    if(game_info->playable[game_info->row][game_info->column + 1] != WALL && game_info->playable[game_info->row][game_info->column + 1] != 'O')
    {
        game_info->modified = 1;
        game_info->playable[game_info->row][game_info->column + 1] = 'O';
    }  

        
}

int     find_playable(so_long_t *game_info)
{
        game_info->modified = 0;
        game_info->row = 0;
        while(game_info->playable[game_info->row] != NULL)
        {
            game_info->column = 0;
            while(game_info->playable[game_info->row][game_info->column] != '\0')
            {
                if(game_info->playable[game_info->row][game_info->column] == 'O')
                    mark_playable(game_info);
                game_info->column++;
            }
            game_info->row++;
        }
        return (0);
}

int     ft_player_location(so_long_t *game_info)
{
    game_info->row = 0;
    while(game_info->playable[game_info->row] != NULL)
    {
        game_info->column = 0;
        while(game_info->playable[game_info->row][game_info->column] != 0)
        {
            if(game_info->playable[game_info->row][game_info->column] == PLAYER)
            {
                game_info->player_x = game_info->row;
                game_info->player_y = game_info->column;
                game_info->playable[game_info->row][game_info->column] = 'O';
            }
            game_info->column++;
        }
        game_info->row++;
    }
    game_info->modified = 1;
    while(game_info->modified == 1)
        find_playable(game_info);
    if(ft_is_winniable(game_info) != 0)
        return (1);
    return (0);
}

int     ft_error(so_long_t *game_info)
{
    if(ft_check_map_chars(game_info->map_raw) == 1)
        return (1);
    if(ft_validate_player_collectibles_exit(game_info) == 1)
        return (1);
    if(ft_check_shape(game_info) == 1)
        return (1);
    if(ft_wall_check(game_info) == 1)
        return (1);
    if(ft_player_location(game_info) == 1)
        return (1);
    return (0);
}