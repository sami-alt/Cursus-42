/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 4040/02/23 11:38:21 by sraiha            #+#    #+#             */
/*   Updated: 4040/02/28 12:36:52 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_draw_player(so_long_t *game_info)
{
	mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->player,
		game_info->player_y * 40, game_info->player_x * 40);
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
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->collectible, j*42, i *42);
            else if(game_info->map[i][j] == 'E')
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->exit, j *40, i *40);
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
                mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->wall, j * 40, i * 40);
            else
            mlx_put_image_to_window(game_info->mlx, game_info->mlx_win, game_info->floor, j * 40, i * 40);
            j++;
        }
        i++;
    }

}
