/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 11:31:42 by sraiha            #+#    #+#             */
/*   Updated: 2025/02/27 15:11:23 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int    ft_draw_images(so_long_t *game_info)
{
    ft_draw_player(game_info);
    ft_draw_floor_wall(game_info);
    ft_draw_collect_exit(game_info);
    return (0);

}

void    ft_graphics(so_long_t *game_info)
{
    int resolution;

    resolution = 30;
    game_info->player = mlx_file_to_image(game_info->mlx, "assets/xmp/player.xmp",&resolution, &resolution);
    if(!game_info->player)
        end_game_and_free(game_info);
    game_info->wall = mlx_file_to_image(game_info->mlx, "assets/xmp/wall.xmp",&resolution, &resolution);
    if(!game_info->wall)
        end_game_and_free(game_info);
    game_info->exit = mlx_file_to_image(game_info->mlx, "assets/xmp/exit.xmp",&resolution, &resolution);
    if(!game_info->exit)
        end_game_and_free(game_info);
    game_info->collectible = mlx_file_to_image(game_info->mlx, "assets/xmp/collectible.xmp",&resolution, &resolution);
    if(!game_info->collectible)
        end_game_and_free(game_info);
    game_info->floor = mlx_file_to_image(game_info->mlx, "assets/xmp/empty.xmp",&resolution, &resolution);
    if(!game_info->floor)
        end_game_and_free(game_info);
}

void    ft_run(so_long_t *game_info)
{
    int     width;
    int     height;
    width = game_info->width;
    height = game_info->height;

    game_info->mlx = mlx_init();
    game_info->mlx_win = mlx_new_window(game_info->mlx, width * 30, height * 30, "-so-long-");
    game_info->img = mlx_new_image(game_info->mlx, height * 30, width * 30);
    ft_graphics(game_info);
    mlx_loop_hook(game_info->mlx, ft_draw_images, game_info);
    mlx_key_hook(game_info->mlx_win, ft_key_hooks, game_info);
    mlx_hook(game_info->mlx_win, 17, 0 ,ft_end_game, game_info);
    mlx_loop(game_info->mlx);
}