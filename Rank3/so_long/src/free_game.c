/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:09:11 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/28 12:47:32 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void    ft_free_game(so_long_t *game_info)
{
    free(game_info->map_raw);
    if(game_info->map && game_info->playable != NULL)
    {
        game_info->index = 0;
        while(game_info->map[game_info->index] != NULL)
        {
            free(game_info->map[game_info->index]);
            free(game_info->playable[game_info->index]);
            game_info->index++;
        }
        free(game_info->map);
        free(game_info->playable);
    }
}

int ft_quit(so_long_t *game_info)
{
    mlx_destroy_window(game_info->mlx, game_info->mlx_win);
    ft_free_game(game_info);
    exit(EXIT_SUCCESS);
    return (1);
}