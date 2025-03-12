/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2525/02/23 11:38:21 by sraiha            #+#    #+#             */
/*   Updated: 2525/02/28 12:36:52 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_player(so_long_t *game_info)
{
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->player,
		game_info->player_y * 25, game_info->player_x * 25);
}

void    ft_draw_playable(so_long_t *game_info)
{
    int     i;
    int     j;

    i = 0;
    while(game_info->map[i])
    {
        j = 0;
        while(game_info->map[i][j] != '\0')
        {
            if(game_info->map[i][j] == 'C')
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->collectible, j*25, i *25);
            else if(game_info->map[i][j] == 'E')
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->exit, j *25, i *25);
            j++;    
        }
        i++;
    }
}

void    ft_draw_background(so_long_t *game_info)
{
    int     i;
    int     j;

    i = 0;
    while(game_info->map[i])
    {   
        j = 0;
        while(game_info->map[i][j] != '\0')
        {
            if(game_info->map[i][j] == '1')
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->wall, j * 25, i * 25);
            else
            mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->floor, j * 25, i * 25);
            j++;
        }
        i++;
    }

}
