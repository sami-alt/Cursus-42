/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraiha <sraiha@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2525/02/23 11:31:42 by sraiha            #+#    #+#             */
/*   Updated: 2525/02/28 12:54:32 by sraiha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int    ft_draw_images(so_long_t *game_info)
{
    ft_draw_background(game_info);
    ft_draw_playable(game_info);
    ft_draw_player(game_info);
    return (0);

}

void    ft_graphics(so_long_t *game_info)
{
    int resolution;
    resolution = 25;
    game_info->player = mlx_xpm_file_to_image(game_info->mlx, "assets/xmp/player.xpm",&resolution, &resolution);
    if(!game_info->player)
        ft_quit(game_info);
    game_info->wall = mlx_xpm_file_to_image(game_info->mlx, "assets/xmp/wall.xpm",&resolution, &resolution);
    if(!game_info->wall)
        ft_quit(game_info);
    game_info->exit = mlx_xpm_file_to_image(game_info->mlx, "assets/xmp/exit.xpm",&resolution, &resolution);
    if(!game_info->exit)
        ft_quit(game_info);
    game_info->collectible = mlx_xpm_file_to_image(game_info->mlx, "assets/xmp/collectible.xpm",&resolution, &resolution);
    if(!game_info->collectible)
        ft_quit(game_info);
    game_info->floor = mlx_xpm_file_to_image(game_info->mlx, "assets/xmp/empty.xpm",&resolution, &resolution);
    if(!game_info->floor)
        ft_quit(game_info);    
}

void    ft_run(so_long_t *game_info)
{
    int     width;
    int     height;
    width = game_info->width;
    height = game_info->height;

    game_info->mlx = mlx_init();
    game_info->mlx_win = mlx_new_window(game_info->mlx, width * 25, height * 25, "-so-long-");
    game_info->img = mlx_new_image(game_info->mlx, height * 25, width * 25);
    ft_graphics(game_info);
    mlx_loop_hook(game_info->mlx, ft_draw_images, game_info);
    mlx_key_hook(game_info->mlx_win, ft_key_hooks, game_info);
    mlx_hook(game_info->mlx_win, 17, 0, ft_quit, game_info);
    mlx_loop(game_info->mlx);
}